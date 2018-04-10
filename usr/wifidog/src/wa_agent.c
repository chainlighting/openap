#ifndef __AUDIT_AGENT_C__
#define __AUDIT_AGENT_C__
#include "wa_agent.h"

#define MAC_2_OUI_TBL_SIZE            16384
#define MAC_2_OUI_LINE_SIZE_MAX       1024
#define MAC_2_OUI_TBL_FILE_DEFAULT    "/etc/wifidog/mac.oui"

#define SIOCGIWRTLSCANREQ             0x8B33  // scan request
#define SIOCGIWRTLGETBSSDB            0x8B34  // get bss data base
#define SIOCGIWRTLGETBSS_STADB        0x8B4A

#define GW_EX_INTF_NUM_MAX            4
#define GW_EX_INTF_CLIENT_NUM_MAX     64
#define GW_EX_INTF_PORT_RANGE_BGN     20000
#define GW_EX_INTF_PORT_SEG_SIZE      500

static int s_mac2oui_tbl_loaded = 0;
static jwHashTable* s_mac2oui_tbl = NULL;

typedef enum _Capability {
    cESS            = 0x01,
    cIBSS           = 0x02,
    cPollable       = 0x04,
    cPollReq        = 0x01,
    cPrivacy        = 0x10,
    cShortPreamble  = 0x20,
} Capability;

typedef struct _BssStaDesc {
    unsigned char bssid[6];
    unsigned char ssid[32];
    unsigned char* ssidptr;         // unused, for backward compatible
    unsigned short ssidlen;
    unsigned int bsstype;
    unsigned short capability;
    unsigned char bdsa[6];          // SA address
    unsigned char rssi, sq;         // RSSI and signal strength
}BssStaDesc,*pBssStaDesc;


typedef struct _sitesurvey_status {
    unsigned char number;
    unsigned char pad[3];
    BssStaDesc bssdb[64];
} SS_STATUS_T, *SS_STATUS_Tp;

typedef struct {
    uint16 idx;
    uint16 occupied;
    uint16 ex_tcp_port_bgn;
    uint16 ex_tcp_port_end;
    uint16 ex_udp_port_bgn;
    uint16 ex_udp_port_end;
}GW_EX_PORT_RES;

typedef struct {
    char* intf;
    char* ip_addr;
    int ex_res_num;
    GW_EX_PORT_RES port_res[GW_EX_INTF_CLIENT_NUM_MAX];
}GW_EX_INTF_RES;

typedef struct {
    int ex_intf_num;
    GW_EX_INTF_RES intf_res[GW_EX_INTF_NUM_MAX];
}GW_EX_RES;

static pthread_mutex_t s_gw_ex_res_lock = PTHREAD_MUTEX_INITIALIZER;
static GW_EX_RES* s_gw_ex_res = NULL;

/*
* strip header's BLANK and tail's \r \n BLANK
*/
static char*
line_strip(
char* line
){
    char* p1 = NULL;
    char* p2 = NULL;

    if(NULL == line) return NULL;

    /*trim header's BLANK*/
    for (p1 = line; isblank(*p1); p1++) ;

    /* End at end of line */
    if ((p2 = strchr(p1, '\r')) != NULL) {
        *p2 = '\0';
    } else if ((p2 = strchr(p1, '\n')) != NULL) {
        *p2 = '\0';
    }

    /* trim all blanks at the end of the line */
    if(NULL != p2) {
        for (p2 = p2 - 1; isblank(*p2) && p2 > p1; p2--) {
            *p2 = '\0';
        }
    }

    return p1;
}

/**
* parse str mac to hex
*/
static unsigned char
char2hex(
    char c
){
    if (c >= '0' && c <= '9')
    {
        return (c - '0');
    }
    else if (c >= 'A' && c <= 'f')
    {
        return (c - 'A' + 10);
    }  
    else if (c >= 'a' && c <= 'f')
    {
        return (c - 'a' + 10);
    }
    else
    {
        debug(LOG_ERR,"char2hex(%c) convert failed!",c);
    }
    
    return 0;
}

static int
str2mac(
    char* pstr,
    uint8* pmachex
){
    int i;
    
    if((NULL == pstr) || (NULL == pmachex)) return -1;

    for(i = 0; i < 6; i++) {
        pmachex[i] = (char2hex(*pstr) & 0xf) << 4;
        pmachex[i] |= (char2hex(*(pstr + 1))) &0xf;
        /*skip seperate*/
        pstr = pstr + 3;
    }
    return 1;
}

static void
mac2oui_tbl_init()
{
    if(NULL == s_mac2oui_tbl) {
        s_mac2oui_tbl = create_hash(MAC_2_OUI_TBL_SIZE);
    }
}

int
mac2oui_tbl_load(
    char* cfgFile
){
    FILE *fd = NULL;
    char* filename = cfgFile;
    char line[MAC_2_OUI_LINE_SIZE_MAX];
    char* tmp_ptr = NULL;
    char* mac_key = NULL;
    char* oui_val = NULL;

    mac2oui_tbl_init();
    if(0 < s_mac2oui_tbl_loaded) {
        return 1;
    }

    if(NULL == filename) {
        filename = MAC_2_OUI_TBL_FILE_DEFAULT;
    }

    if (NULL == (fd = fopen(filename, "r"))) {
        debug(LOG_ERR,"mac2oui can't find config file(%s)\n",filename);
        return -1;
    }

    while (!feof(fd) && fgets(line, MAC_2_OUI_LINE_SIZE_MAX, fd)) {
        tmp_ptr = line_strip(line);
        oui_val = NULL;
        mac_key = strtok_r(tmp_ptr," ",&oui_val);
        if((NULL != mac_key) && (NULL != oui_val)) {
            add_str_by_str(s_mac2oui_tbl,mac_key,oui_val);
        } else {
            break;
        }
    }

    s_mac2oui_tbl_loaded = 1;
    
    return 1;
}

int
mac2oui_tbl_search(
    uint8* mac_ind,
    char* oui_buf,
    int   oui_buf_len
){
    char* oui_val = NULL;
    int oui_val_len = 0;
    char mac_key[8];

    if((NULL == mac_ind) || (NULL == oui_buf)) {
        return -1;
    }

    if(NULL == s_mac2oui_tbl) {
        return -1;
    }

    /*convert mac_ind to UPPER*/
    snprintf(&mac_key[0],sizeof(mac_key),"%02X%02X%02X",
        mac_ind[0],mac_ind[1],mac_ind[2]);
    
    get_str_by_str(s_mac2oui_tbl,mac_key,&oui_val);
    if((NULL != oui_val) && (oui_buf_len > (oui_val_len = strlen(oui_val)))) {
        memcpy(oui_buf,oui_val,oui_val_len);
        oui_buf[oui_val_len] = '\0';
    } else {
        memcpy(oui_buf,"OTHER",strlen("OTHER"));
        oui_buf[strlen("OTHER")] = '\0';
    }

    return 1;
}

static int
iw_get_ext(
    int skfd,             /* Socket to the kernel */
    char* ifname,         /* Device name */
    int request,          /* WE ID */
    struct iwreq* pwrq)   /* Fixed part of the request */
{
  /* Set device name */
  strncpy(pwrq->ifr_name, ifname, IFNAMSIZ);
  /* Do the request */
  return(ioctl(skfd, request, pwrq));
}

static int 
wa_probe_survey_req(
    char* ifname,
    int* pStatus
){
#ifndef NO_ACTION
    int skfd=0;
    struct iwreq wrq;
    unsigned char result;

    skfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(skfd==-1)
        return -1;

    /* Get wireless name */
    if ( iw_get_ext(skfd, ifname, SIOCGIWNAME, &wrq) < 0){
        /* If no wireless name : no wireless extensions */
        close( skfd );
        return -1;
    }
    wrq.u.data.pointer = (caddr_t)&result;
    wrq.u.data.length = sizeof(result);

    iw_get_ext(skfd, ifname, SIOCGIWRTLSCANREQ, &wrq);
    close( skfd );

    if ( result == 0xff )
    	*pStatus = -1;
    else
    *pStatus = (int) result;
#else
    *pStatus = -1;
#endif

    return 0;
}

static int
wa_collect_survey_result(
    char* ifname,
    SS_STATUS_Tp pStatus
){
#ifndef NO_ACTION
    int skfd=0;
    struct iwreq wrq;

    skfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(skfd==-1)
        return -1;
    /* Get wireless name */
    if ( iw_get_ext(skfd, ifname, SIOCGIWNAME, &wrq) < 0){
        /* If no wireless name : no wireless extensions */
        close( skfd );
        debug(LOG_ERR,"ioctl(%x) error!\n",SIOCGIWNAME);
        return -1;
    }
    wrq.u.data.pointer = (caddr_t)pStatus;

    if ( pStatus->number == 0 )
    	wrq.u.data.length = sizeof(SS_STATUS_T);
    else
        wrq.u.data.length = sizeof(pStatus->number);

    if (iw_get_ext(skfd, ifname, SIOCGIWRTLGETBSSDB, &wrq) < 0){
        close( skfd );
        debug(LOG_ERR,"ioctl(%x) error!\n",SIOCGIWRTLGETBSSDB);
        return -1;
    }
    close( skfd );
#else
    return -1 ;
#endif

    return 0;
}

/*
* thread safe sleep
*/
void
wa_thd_sleep(
    int interval_s
){
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    pthread_mutex_t cond_mutex = PTHREAD_MUTEX_INITIALIZER;
    struct timespec timeout;
    
    /* Sleep for config.checkinterval seconds... */
    timeout.tv_sec = time(NULL) + interval_s;
    timeout.tv_nsec = 0;

    /* Mutex must be locked for pthread_cond_timedwait... */
    pthread_mutex_lock(&cond_mutex);

    /* Thread safe "sleep" */
    pthread_cond_timedwait(&cond, &cond_mutex, &timeout);

    /* No longer needs to be locked */
    pthread_mutex_unlock(&cond_mutex);
}

/*
* wifi audit msg send
*/
int
wa_msg_send(
    char* serverIp,
    char* serverPort,
    CMCC_MSG_TYPE msgType,
    CMCC_MSG_DATA* msgData
){
    CMCC_PROBE_INFO* pProbe = NULL;
    char buf[2048];
    int data_len;
    int tmp_len;
    int buf_left;
    int i;

    int sockFd = -1;
    struct sockaddr_in address;
    
    /*init network*/
    bzero(&address,sizeof(address));
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr(serverIp);
    address.sin_port=htons(atoi(serverPort));
    
    sockFd = socket(AF_INET,SOCK_DGRAM,0);
    if(0 > sockFd) {
        debug(LOG_ERR,"wa_msg_send(%s:%s): socket create failed!",serverIp,serverPort);
        return -1;
    }
    
    /*build msg*/
    switch(msgType) {
        case CMCC_ONLINE_MSG:
            data_len = snprintf(buf,sizeof(buf),
                              "%d#%02X-%02X-%02X-%02X-%02X-%02X#%d#%d#%s",
                              CMCC_ONLINE_MSG,
                              msgData->client_mac[0],msgData->client_mac[1],msgData->client_mac[2],
                              msgData->client_mac[3],msgData->client_mac[4],msgData->client_mac[5],
                              msgData->client_ex_port_bgn,msgData->client_ex_port_end,
                              msgData->client_phone_num);
            break;
        case CMCC_OFFLINE_MSG:
            data_len = snprintf(buf,sizeof(buf),
                              "%d#%02X-%02X-%02X-%02X-%02X-%02X",
                              CMCC_OFFLINE_MSG,
                              msgData->client_mac[0],msgData->client_mac[1],msgData->client_mac[2],
                              msgData->client_mac[3],msgData->client_mac[4],msgData->client_mac[5]);
            break;
        case CMCC_PROBE_MSG:
            data_len = snprintf(buf,sizeof(buf),
                              "#%d#%d",
                              CMCC_PROBE_MSG,
                              msgData->probeNum);
            buf_left = sizeof(buf) - data_len;
            for(i = 0; i < msgData->probeNum; i++) {
                pProbe = &(msgData->pProbeInfo[i]);
                tmp_len = snprintf(buf + data_len,buf_left,
                              "#%02X-%02X-%02X-%02X-%02X-%02X\t%s\t%s\t%d\t%d\t%d\t%d\t%c",
                              pProbe->m_dev_mac[0],pProbe->m_dev_mac[1],pProbe->m_dev_mac[2],
                              pProbe->m_dev_mac[3],pProbe->m_dev_mac[4],pProbe->m_dev_mac[5],
                              pProbe->o_dev_vendor,pProbe->o_dev_cached_ssid,pProbe->m_dev_sampled_utc_sec,
                              pProbe->m_dev_sampled_rssi,pProbe->o_dev_pos_x,pProbe->o_dev_pos_y,
                              pProbe->m_dev_isAp);
                if(tmp_len > (buf_left - 1)) {
                    debug(LOG_WARNING,"wa_msg_send: msg is too large,we just drop it\n");
                    return -1;
                }
                data_len = data_len + tmp_len;
                buf_left = buf_left - tmp_len;
            }
            break;
        default:
            debug(LOG_INFO,"wa_msg_send(%s:%s): msgType(%d) is unkonwn!",msgType,serverIp,serverPort);
            return -1;
    }

    /*send the msg*/
    debug(LOG_INFO,"msg(%d) send to %s:%s\n%s\n",
        msgType,serverIp,serverPort,buf);
    sendto(sockFd,buf,data_len,0,(struct sockaddr *)&address,sizeof(address));
    close(sockFd);
    return 1;
}

/*
* wifi audit msg send to audit servers
*/
void
wa_audit_send(
    CMCC_MSG_TYPE msgType,
    CMCC_MSG_DATA* msgData
){
    t_wa_serv* pWAServ = NULL;
    s_config *config = config_get_config();
    
    pWAServ = config->wa_servers;
    while(NULL != pWAServ) {
        wa_msg_send(pWAServ->hostname,pWAServ->port,msgType,msgData);
        pWAServ = pWAServ->next;
    }
}

/*
* wifi probe
* this routine should be thread call
*/
int
wa_probe_survey(
    char* intf
){
    int i;
    int status = -1;
    int chk_loops;
    uint8 rtn_scan;
    SS_STATUS_T scan_rlt;
    CMCC_PROBE_INFO* pProbeInfo;
    CMCC_MSG_DATA msgData;
    s_config *config = config_get_config();

    /*probe request*/
    if(0 < config->wa_probe_enable) {
        chk_loops = config->wa_probe_req_retries;
        while(chk_loops) {
            if(0 != wa_probe_survey_req(intf,&status)) {
                debug(LOG_ERR,"survey requst to %s failed(0)!",intf);
                return -1;
            }

            if(0 != status) {
                chk_loops = chk_loops - 1;
                wa_thd_sleep(config->wa_probe_req_waittime);
            } else {
                break;
            }
        }
        if(0 != status) {
            debug(LOG_ERR,"survey request to %s failed(1)!",intf);
            return -1;
        }
    }

    /*check scan progress*/
    chk_loops = config->wa_probe_req_retries;
    while(chk_loops) {
        rtn_scan = 3;
        /*check valid collect survey site&sta number*/
        if(wa_collect_survey_result(intf,(SS_STATUS_Tp)&rtn_scan) < 0) {
            debug(LOG_ERR,"collect survey result from %s failed!",intf);
            return -1;
        }
        
        if(0xff == rtn_scan) {
            /*scanning*/
            chk_loops = chk_loops - 1;
            wa_thd_sleep(config->wa_probe_req_waittime);
        } else {
            /*scan complete*/
            break;
        }
    }
    if(0xff != rtn_scan) {
        scan_rlt.number = 4; /*request BSS DB*/
        /*get collected survey site&sta information*/
        if(wa_collect_survey_result(intf, &scan_rlt) < 0) {
            debug(LOG_WARNING,"no valid site&sta be found at %s!",intf);
            return -1;
        }

        if(0 == scan_rlt.number) {
            return 0;
        }
        
        msgData.probeNum = scan_rlt.number;
        msgData.pProbeInfo = malloc(sizeof(CMCC_PROBE_INFO)*msgData.probeNum);
        if(NULL == msgData.pProbeInfo) {
            debug(LOG_ERR,"malloc memory failed!");
            return -1;
        }
        for(i = 0; i < msgData.probeNum; i++) {
            pProbeInfo = &(msgData.pProbeInfo[i]);
            memcpy(&(pProbeInfo->m_dev_mac[0]),&(scan_rlt.bssdb[i].bdsa[0]),sizeof(pProbeInfo->m_dev_mac));
            pProbeInfo->m_dev_isAp = (scan_rlt.bssdb[i].capability & cIBSS) ? 'N' : 'Y';
            pProbeInfo->m_dev_sampled_rssi = scan_rlt.bssdb[i].rssi;
            pProbeInfo->m_dev_sampled_utc_sec = time(NULL);

            memcpy(pProbeInfo->o_dev_cached_ssid,scan_rlt.bssdb[i].ssid,scan_rlt.bssdb[i].ssidlen);
            pProbeInfo->o_dev_cached_ssid[scan_rlt.bssdb[i].ssidlen] = '\0';

            pProbeInfo->o_dev_pos_x = 0;
            pProbeInfo->o_dev_pos_y = 0;

            mac2oui_tbl_search(&(pProbeInfo->m_dev_mac[0]),
                &(pProbeInfo->o_dev_vendor[0]),
                sizeof(pProbeInfo->o_dev_vendor));
        }

        /*send to wifi-audit server*/
        debug(LOG_INFO,"get %d site|sta from %s,try to send to audit-server.",msgData.probeNum,intf);
        wa_audit_send(CMCC_PROBE_MSG,&msgData);
        
        free(msgData.pProbeInfo);
        return 1;
    }

    return -1;
}

static int
wa_gw_ex_res_init(
    int ex_intf_num,
    int ex_res_num,
    unsigned short ex_port_range_bgn,
    unsigned short ex_port_seg_size
){
    int i,j;
    unsigned short tmp_port_bgn;
    int rlt = -1;

    pthread_mutex_lock(&s_gw_ex_res_lock);

    if(NULL != s_gw_ex_res){
        rlt = 1;
        goto go_return;
    } else {
        s_gw_ex_res = malloc(sizeof(GW_EX_RES));
        if(NULL == s_gw_ex_res) {
            debug(LOG_ERR,"gw_ex_res_init alloc memory failed!");
            exit(-1);
        }
        memset(s_gw_ex_res,0,sizeof(s_gw_ex_res));
    }
    
    s_gw_ex_res->ex_intf_num = ex_intf_num;

    for(i = 0; i < s_gw_ex_res->ex_intf_num; i++){
        tmp_port_bgn = ex_port_range_bgn;
        s_gw_ex_res->intf_res[i].intf = NULL;
        s_gw_ex_res->intf_res[i].ip_addr = NULL;
        s_gw_ex_res->intf_res[i].ex_res_num = ex_res_num;
        for(j = 0; j < ex_res_num; j++){
            s_gw_ex_res->intf_res[i].port_res[j].ex_tcp_port_bgn = tmp_port_bgn;
            s_gw_ex_res->intf_res[i].port_res[j].ex_tcp_port_end = tmp_port_bgn + ex_port_seg_size;
            s_gw_ex_res->intf_res[i].port_res[j].ex_udp_port_bgn = tmp_port_bgn;
            s_gw_ex_res->intf_res[i].port_res[j].ex_udp_port_end = tmp_port_bgn + ex_port_seg_size;
            s_gw_ex_res->intf_res[i].port_res[j].idx = j;
            s_gw_ex_res->intf_res[i].port_res[j].occupied = 0;

            tmp_port_bgn = tmp_port_bgn + ex_port_seg_size + 1;
        }
    }
    rlt = 1;
    
go_return:
    pthread_mutex_unlock(&s_gw_ex_res_lock);
    return rlt;
}

/**
* try to get external interface and ip address
*/
static int
wa_get_external_intf_info(
){
    int rlt = -1;
    GW_EX_INTF_RES* tmp_intf_res = NULL;
    const s_config *config;
    
    if(NULL == s_gw_ex_res) goto go_return;
    if(0 == s_gw_ex_res->ex_intf_num) goto go_return;

    config = config_get_config();
    /*Note: now we just set one external interface information*/
    tmp_intf_res = &s_gw_ex_res->intf_res[0];
    if(NULL == tmp_intf_res->intf) {
        if(NULL != config->external_interface) {
            tmp_intf_res->intf = safe_strdup(config->external_interface);
        } else {
            tmp_intf_res->intf = get_ext_iface();
        }
    }
    if(NULL != tmp_intf_res->intf) {
        if(NULL == tmp_intf_res->ip_addr) {
            tmp_intf_res->ip_addr = get_iface_ip(tmp_intf_res->intf);
        }
    } else {
        debug(LOG_WARNING,"can't find external interface!");
    }

    if(NULL == tmp_intf_res->ip_addr) {
        debug(LOG_WARNING,"cant't find external interface's ipaddress!");
    }
    rlt = 1;
    
go_return:
    return rlt;
}

/**
* wifi portal external port resource alloc for client
* Note: now we just get one external interface
*/
static int
wa_gw_ex_res_alloc(
    t_client* client
){
    int j;
    int rlt = -1;
    GW_EX_INTF_RES* tmp_intf_res = NULL;

    pthread_mutex_lock(&s_gw_ex_res_lock);
    
    if(NULL == client) goto go_return;
    if(NULL == s_gw_ex_res) goto go_return;
    if(0 == s_gw_ex_res->ex_intf_num) goto go_return;

    /*try to check external interface and it's ipaddr*/
    tmp_intf_res = &s_gw_ex_res->intf_res[0];
    if((NULL == tmp_intf_res->intf) || (NULL == tmp_intf_res->ip_addr)) {
        wa_get_external_intf_info();
    }

    /*try to alloc port resource to client*/
    if((NULL != tmp_intf_res->intf) && (NULL != tmp_intf_res->ip_addr)) {
        for(j = 0; j < tmp_intf_res->ex_res_num; j++){
            if(0 == tmp_intf_res->port_res[j].occupied) {
                /*set alloc port resource*/
                client->port_res.ex_tcp_port_bgn = tmp_intf_res->port_res[j].ex_tcp_port_bgn;
                client->port_res.ex_tcp_port_end = tmp_intf_res->port_res[j].ex_tcp_port_end;
                client->port_res.ex_udp_port_bgn = tmp_intf_res->port_res[j].ex_udp_port_bgn;
                client->port_res.ex_udp_port_end = tmp_intf_res->port_res[j].ex_udp_port_end;
                client->port_res.ex_port_range_idx = tmp_intf_res->port_res[j].idx;
                if(NULL != client->port_res.ex_intf) free(client->port_res.ex_intf);
                client->port_res.ex_intf = safe_strdup(tmp_intf_res->intf);
                if(NULL != client->port_res.ex_ip) free(client->port_res.ex_ip);
                client->port_res.ex_ip = safe_strdup(tmp_intf_res->ip_addr);
                tmp_intf_res->port_res[j].occupied = 1;
                rlt = 1;
                goto go_return;
            }
        }
    }
    
go_return:
    pthread_mutex_unlock(&s_gw_ex_res_lock);
    return rlt;
}

/**
* wifi portal external port resource free from client
* Note: now we just have one external interface to alloc port resource
*/
static int
wa_gw_ex_res_free(
    t_client* client
){
    int rlt = -1;
    GW_EX_INTF_RES* tmp_intf_res = NULL;

    pthread_mutex_lock(&s_gw_ex_res_lock);
    
    if(NULL == client) goto go_return;
    if(NULL == s_gw_ex_res) goto go_return;
    if(0 == s_gw_ex_res->ex_intf_num) goto go_return;

    tmp_intf_res = &s_gw_ex_res->intf_res[0];
    if(client->port_res.ex_port_range_idx >= tmp_intf_res->ex_res_num){
        goto go_return;
    }
    tmp_intf_res->port_res[client->port_res.ex_port_range_idx].occupied = 0;
    
    if(NULL != client->port_res.ex_intf) {
        free(client->port_res.ex_intf);
        client->port_res.ex_intf = NULL;
    }
    if(NULL != client->port_res.ex_ip) {
        free(client->port_res.ex_ip);
        client->port_res.ex_ip = NULL;
    }
    
    rlt = 1;
    
go_return:
    pthread_mutex_unlock(&s_gw_ex_res_lock);
    return rlt;
}

/**
* wifi portal online/offline audit process
* para:
* @act: online or offline
* @client_ip: the ip address of client
* @client_res: the ex-resource alloced to client for internet accessing
*/
void
wa_client_audit(
    ACTIVITY_AUDIOT act,
    t_client* client,
    int sendMsg
){
    CMCC_MSG_DATA msgData;
    
    if(NULL == client) return;

    memset(&msgData,0,sizeof(CMCC_MSG_DATA));
    
    switch(act) {
        case ACT_ONLINE_AUDIOT:
            wa_gw_ex_res_alloc(client);
            if((NULL != client->port_res.ex_intf) && (NULL != client->port_res.ex_ip)) {
                iptables_do_command("-t nat -I POSTROUTING -s %s -p tcp -o %s -j SNAT --to %s:%d-%d",
                    client->ip,client->port_res.ex_intf,
                    client->port_res.ex_ip,client->port_res.ex_tcp_port_bgn,client->port_res.ex_tcp_port_end);
                iptables_do_command("-t nat -I POSTROUTING -s %s -p udp -o %s -j SNAT --to %s:%d-%d",
                    client->ip,client->port_res.ex_intf,
                    client->port_res.ex_ip,client->port_res.ex_udp_port_bgn,client->port_res.ex_udp_port_end);
            }
            msgData.client_ex_port_bgn = client->port_res.ex_tcp_port_bgn;
            msgData.client_ex_port_end = client->port_res.ex_tcp_port_end;
            if(NULL != client->mac) {
                str2mac(client->mac,msgData.client_mac);
            }
            if(sendMsg) { wa_audit_send(CMCC_ONLINE_MSG,&msgData); }
            break;
        case ACT_OFFLINE_AUDIOT:
            if((NULL != client->port_res.ex_intf) && (NULL != client->port_res.ex_ip)) {
                iptables_do_command("-t nat -D POSTROUTING -s %s -p tcp -o %s -j SNAT --to %s:%d-%d",
                    client->ip,client->port_res.ex_intf,
                    client->port_res.ex_ip,client->port_res.ex_tcp_port_bgn,client->port_res.ex_tcp_port_end);
                iptables_do_command("-t nat -D POSTROUTING -s %s -p udp -o %s -j SNAT --to %s:%d-%d",
                    client->ip,client->port_res.ex_intf,
                    client->port_res.ex_ip,client->port_res.ex_udp_port_bgn,client->port_res.ex_udp_port_end);
            }
            if(NULL != client->mac) {
                str2mac(client->mac,msgData.client_mac);
            }
            if(sendMsg) { wa_audit_send(CMCC_OFFLINE_MSG,&msgData); }
            wa_gw_ex_res_free(client);
            break;
        default:
            break;
    }
}

/*
* wifi audit survey process thread
*/
void
wa_thread_wifi_audit(void* arg)
{
    int wait_time = 5;
    s_config *config = config_get_config();

    /*init mac to oui table*/
    mac2oui_tbl_load(NULL);
    /*init external internet interface port resource*/
    wa_gw_ex_res_init(1,GW_EX_INTF_CLIENT_NUM_MAX,GW_EX_INTF_PORT_RANGE_BGN,GW_EX_INTF_PORT_SEG_SIZE);
    
    while (1) {
        if(0 < config->wa_enable) {
            debug(LOG_DEBUG, "wifi-audit to start site&sta survey");
            wa_probe_survey("wlan0");
            wa_probe_survey("wlan1");
        }
        
        if(0 < config->wa_chk_interval) {
            wait_time = config->wa_chk_interval;
        }
        wa_thd_sleep(wait_time);
    }
}

#endif

