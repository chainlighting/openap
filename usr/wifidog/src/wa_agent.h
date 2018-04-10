#ifndef __AUDIT_AGENT_H__
#define __AUDIT_AGENT_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h> 
#include <assert.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client_list.h"
#include "jwHash.h"
#include <sys/ioctl.h>
#include <linux/wireless.h>
#include "debug.h"
#include <syslog.h>
#include <pthread.h>
#include "conf.h"
#include "safe.h"
#include "util.h"
#include "fw_iptables.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef enum {
    ACT_ONLINE_AUDIOT  = 1,
    ACT_OFFLINE_AUDIOT = 2
}ACTIVITY_AUDIOT;

typedef enum {
    CMCC_ONLINE_MSG    = 100,
    CMCC_OFFLINE_MSG   = 101,
    CMCC_PROBE_MSG     = 102
}CMCC_MSG_TYPE;

typedef struct {
    uint8      m_dev_mac[6];
    char       o_dev_vendor[128];
    /* cached ssids delimited by "," */
    char       o_dev_cached_ssid[64];
    /*collected utc second*/
    int        m_dev_sampled_utc_sec;
    int        m_dev_sampled_rssi;
    int        o_dev_pos_x;
    int        o_dev_pos_y;
    /*Y or N*/
    char       m_dev_isAp;
}CMCC_PROBE_INFO;

typedef struct {
    /*portal info*/
    uint8       client_mac[6];
    uint16      client_ex_port_bgn;
    uint16      client_ex_port_end;
    char        client_phone_num[32];
    /*probe info*/
    int probeNum;
    CMCC_PROBE_INFO* pProbeInfo;
}CMCC_MSG_DATA;

/*
* thread safe sleep
*/
void
wa_thd_sleep(
    int interval_s
);

/*
* wifi audit msg send
*/
int
wa_msg_send(
    char* serverIp,
    char* serverPort,
    CMCC_MSG_TYPE msgType,
    CMCC_MSG_DATA* msgData
);

/*
* wifi audit msg send to audit servers
*/
void
wa_audit_send(
    CMCC_MSG_TYPE msgType,
    CMCC_MSG_DATA* msgData
);


/*
* wifi probe
* this routine should be thread call
*/
int
wa_probe_survey(
    char* intf
);

/*
* wifi audit process thread
*/
void
wa_thread_wifi_audit(
    void* arg
);

/**
* wifi portal online/offline audit process
* para:
* @act: online or offline
* @client: client control struct
*/
void
wa_client_audit(
    ACTIVITY_AUDIOT act,
    t_client* client,
    int sendMsg
);



/*
load mac oui table map from config file.
return: 
(1)->load ok,(-1)->load failed
*/
int
mac2oui_tbl_load(
    char* cfgFile
);

/*
search oui by mac-address's first 3Bytes.
para:
mac_ind, mac-address's first 3Bytes
oui_buf,  oui output buffer
oui_buf_len, oui output buffer len
return:
(1)->found,(-1)->not found
*/
int
mac2oui_tbl_search(
    uint8* mac_ind,
    char* oui_buf,
    int   oui_buf_len
);


#ifdef __cplusplus
}
#endif
#endif

