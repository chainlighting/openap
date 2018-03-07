/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "config_grammar.y" /* yacc.c:339  */

/**
 * A client-side 802.1x implementation supporting EAP/TLS
 *
 * This code is released under both the GPL version 2 and BSD licenses.
 * Either license may be used.  The respective licenses are found below.
 *
 * Copyright (C) 2002 Bryan D. Payne & Nick L. Petroni Jr.
 * All Rights Reserved
 *
 * --- GPL Version 2 License ---
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * --- BSD License ---
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  - All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *       This product includes software developed by the University of
 *       Maryland at College Park and its contributors.
 *  - Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/*******************************************************************
 * Grammar for configuration file
 * 
 * File: config_grammar.y
 *
 * Authors: bdpayne@cs.umd.edu, npetroni@cs.umd.edu
 *
 * $Id: config_grammar.y,v 1.1.1.1 2007/08/06 10:04:42 root Exp $
 * $Date: 2007/08/06 10:04:42 $
 * $Log: config_grammar.y,v $
 * Revision 1.1.1.1  2007/08/06 10:04:42  root
 * Initial import source to CVS
 *
 * Revision 1.1.1.1  2004/08/12 10:33:24  ysc
 *
 *
 * Revision 1.1  2004/07/24 00:52:56  kennylin
 *
 * Client mode TLS
 *
 * Revision 1.1  2004/07/24 00:40:55  kennylin
 *
 * Client mode TLS
 *
 * Revision 1.25  2004/03/26 03:52:47  chessing
 *
 * Fixed a bug in xsup_debug that would cause config-parse to crash.  Added new key word for session resumption.  Added code to attempt session resumption.  So far, testing has not succeeded, but it is attempting resume. (Four TTLS packets are exchanged, and then we get a failure.)  More testing is needed.
 *
 * Revision 1.24  2004/03/24 18:35:46  chessing
 *
 * Added a modified version of a patch from David Relson to fix a problem with some of the debug info in config_grammer.y.  Added some additional checks to eapol_key_type1 that will keep us from segfaulting under some *REALLY* strange conditions.  Changed the set key code in cardif_linux to double check that we aren't a wireless interface before returning an error.  This resolved a problem when XSupplicant was started when an interface was done.  Upon bringing up the interface, XSupplicant would sometimes think it wasn't wireless, and not bother trying to set keys.
 *
 * Revision 1.23  2004/03/22 00:41:00  chessing
 *
 * Added logfile option to the global config options in the config file.  The logfile is where output will go when we are running in daemon mode.  If no logfile is defined, output will go to the console that started xsupplicant.   Added forking to the code, so that when started, the process can daemonize, and run in the background.  If there is a desire to force running in the foreground (such as for debugging), the -f option was added.
 *
 * Revision 1.22  2004/03/15 16:23:24  chessing
 *
 * Added some checks to TLS using EAP types to make sure the root certificate isn't set to NULL.  (If it is, we can't authenticate, so we bail out.)  Changed the user certificate settings in the config file to all start with user_.  So, "cert" is now "user_cert", "key" is now "user_key", and "key_pass" is now "user_key_pass".  The structures and other related variables were also updated to reflect this change.  THIS WILL PROBABLY BREAK CONFIG FILES FOR SOME USERS!  (Be prepared for complaints on the list!)  ;)
 *
 * Revision 1.21  2004/03/06 03:53:54  chessing
 *
 * We now send logoffs when the process is terminated.  Added a new option to the config file "wireless_control" which will allow a user to disable non-EAPoL key changes.  Added an update to destination BSSID checking that will reset the wireless key to all 0s when the BSSID changes.  (This is what "wireless_control" disables when it is set to no.)  Roaming should now work, but because we are resetting keys to 128 bit, there may be issues with APs that use 64 bit keys.  I will test this weekend.
 *
 * Revision 1.20  2004/03/05 23:58:45  chessing
 *
 * Added CN (sometimes called server name) checking to TTLS and PEAP.  This resulted in two new config options in the eap-ttls, and eap-peap blocks.  cncheck should be the name (or partial name) to match in the CN.  cnexact should be yes/no depending on if we want to match the CN exactly, or just see if our substring is in the CN.
 *
 * Revision 1.19  2004/02/16 14:23:49  npetroni
 * updated config code to allow empty method fields in the config file. The format
 * is
 *
 * eap_method {
 *
 * }
 *
 * the semantics are to create a structure of that type and put it in the list for that network, but not to initialize any of the values (they remain NULL, 0, or whatever malloc gives us).
 *
 * Revision 1.18  2004/02/10 03:40:22  npetroni
 * updated config to include a phase 2 identity for PEAP
 *
 * Revision 1.17  2004/01/06 22:25:58  npetroni
 * added crl parameter to tls, ttls, and peap and user cert,key,key_pass to ttls,peap
 *
 * Revision 1.16  2003/12/31 16:16:35  npetroni
 * made some generalizations to the way config code works so that now
 * it is easy to let any method be put inside of PEAP with little effort.
 *
 * Added MD5, SIM to the PEAP config section.
 *
 * Added allow types for OTP and GTC- we still need configuration parameters
 *   for these methods though.
 *
 * this code is coming together I think.
 *
 * Revision 1.15  2003/12/31 07:03:48  npetroni
 * made a number of changes to the config code to generalize handling of EAP
 * methods and phase2. I still need to go back and make the parser work for
 * other phase2 type in PEAP, but the backend is there.
 *
 * Revision 1.14  2003/12/19 23:19:11  npetroni
 * updated config code and test example. Fixed a couple things
 *   1. added new variables to globals:
 *      startup_command
 *      first_auth_command
 *      reauth_command
 *      auth_period
 *      held_period
 *      max_starts
 *      allow_interfaces
 *      deny_ineterfaces
 *
 *   2. added new variables to network:
 *      dest_mac
 *
 *   3. added new variables to ttls:
 *      phase2_type
 *
 *   4. added new variables to peap:
 *      allow_types
 *
 *   5. layed the groundwork for "preferred types" to be sent in Nak
 *
 * Revision 1.13  2003/12/10 14:13:16  npetroni
 * updated configuration code to parse all types. example updated as well
 *
 * Revision 1.12  2003/11/29 01:11:30  npetroni
 * Added first round of configuration code.
 * Structural Changes:
 *    added examle config file and finished config-parser to test configuration
 *    files and optionally dump the output
 *
 * Current Status:
 *   Have not added parameters for any other method than TLS so we can discuss
 *   the changes before doing so.
 *
 *   Did not update config_build() so chris can keep testing as before.
 *
 *
 *******************************************************************/  
  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
  
#include "config.h"
#include "xsup_err.h"
#include "xsup_debug.h"

// there has GOT to be a better way than this...
#include "eap_types/md5/eapmd5.h"
#include "eap_types/tls/eaptls.h"
#include "eap_types/ttls/eapttls.h"
#include "eap_types/mschapv2/eapmschapv2.h"
#include "eap_types/peap/eappeap.h"
#include "eap_types/leap/eapleap.h"
#ifndef EAP_SIM_ENABLE
#define EAP_SIM_ENABLE
#endif 
#include "eap_types/sim/eapsim.h"

#define CLEAN_EXIT cleanup_parse(); return XECONFIGPARSEFAIL

int yylex(void);  
int yyerror(char *err);
extern struct config_data *config_info;

extern int config_parse_debug;

struct config_data *tmp_config = NULL;

struct config_eap_tls *tmp_tls = NULL;
struct config_eap_md5 *tmp_md5 = NULL;
struct config_eap_ttls *tmp_ttls = NULL;
struct config_eap_leap *tmp_leap = NULL;
struct config_eap_mschapv2 *tmp_mschapv2 = NULL;
struct config_eap_peap *tmp_peap = NULL; 
struct config_eap_sim *tmp_sim = NULL;

struct config_pap *tmp_p2pap =NULL;
struct config_chap *tmp_p2chap = NULL;
struct config_mschap *tmp_p2mschap = NULL;
struct config_mschapv2 *tmp_p2mschapv2 = NULL;

struct config_network *tmp_network = NULL;



void set_current_tls() {
  if (tmp_tls == NULL) 
    initialize_config_eap_tls(&tmp_tls);
} 
void set_current_md5() {
  if (tmp_md5 == NULL) 
    initialize_config_eap_md5(&tmp_md5);
} 
void set_current_ttls() {
  if (tmp_ttls == NULL) 
    initialize_config_eap_ttls(&tmp_ttls);
} 
void set_current_leap() {
  if (tmp_leap == NULL) 
    initialize_config_eap_leap(&tmp_leap);
} 
void set_current_mschapv2() {
  if (tmp_mschapv2 == NULL) 
    initialize_config_eap_mschapv2(&tmp_mschapv2);
} 
void set_current_peap() {
  if (tmp_peap == NULL) 
    initialize_config_eap_peap(&tmp_peap);
} 
void set_current_sim() {
  if (tmp_sim == NULL) 
    initialize_config_eap_sim(&tmp_sim);
} 

void set_current_p2pap() {
  if (tmp_p2pap == NULL)
    initialize_config_pap(&tmp_p2pap);
}
void set_current_p2chap() {
  if (tmp_p2chap == NULL)
    initialize_config_chap(&tmp_p2chap);
}
void set_current_p2mschap() {
  if (tmp_p2mschap == NULL)
    initialize_config_mschap(&tmp_p2mschap);
}
void set_current_p2mschapv2() {
  if (tmp_p2mschapv2 == NULL)
    initialize_config_mschapv2(&tmp_p2mschapv2);
}

void set_current_config() {
  if (tmp_config == NULL) 
    initialize_config_data(&tmp_config);
} 

void set_current_globals() {
  set_current_config();
  if (!tmp_config->globals)
    initialize_config_globals(&(tmp_config->globals));
}   

void set_current_network() {
  if (tmp_network == NULL) 
    initialize_config_network(&tmp_network);
} 


void cleanup_parse()
{
  if (tmp_config)
    delete_config_data(&tmp_config);
  if (tmp_tls)
    delete_config_eap_tls(&tmp_tls);
  if (tmp_md5)
    delete_config_eap_md5(&tmp_md5);
  if (tmp_ttls)
    delete_config_eap_ttls(&tmp_ttls);
  if (tmp_leap)
    delete_config_eap_leap(&tmp_leap);
  if (tmp_mschapv2)
    delete_config_eap_mschapv2(&tmp_mschapv2);
  if (tmp_peap)
    delete_config_eap_peap(&tmp_peap);
  if (tmp_sim)
    delete_config_eap_sim(&tmp_sim);
  if (tmp_p2pap)
    delete_config_pap(&tmp_p2pap);
  if (tmp_p2chap)
    delete_config_chap(&tmp_p2chap);
  if (tmp_p2mschap)
    delete_config_mschap(&tmp_p2mschap);
  if (tmp_p2mschapv2)
    delete_config_mschapv2(&tmp_p2mschapv2);
  if (tmp_network)
    delete_config_network(&tmp_network);
}



/* function to check if debug is on and if so print the message */
void parameter_debug(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  if (!config_parse_debug) return;

  vprintf(fmt, ap);
  va_end(ap);
}


#line 396 "config_grammar.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_NETWORK_LIST = 258,
    TK_DEFAULT_NETNAME = 259,
    TK_NETNAME = 260,
    TK_STARTUP_COMMAND = 261,
    TK_FIRST_AUTH_COMMAND = 262,
    TK_REAUTH_COMMAND = 263,
    TK_LOGFILE = 264,
    TK_AUTH_PERIOD = 265,
    TK_HELD_PERIOD = 266,
    TK_MAX_STARTS = 267,
    TK_ALLOW_INTERFACES = 268,
    TK_DENY_INTERFACES = 269,
    TK_ALL = 270,
    TK_TYPE = 271,
    TK_ALLOW_TYPES = 272,
    TK_WIRELESS = 273,
    TK_WIRED = 274,
    TK_CONTROL_WIRELESS = 275,
    TK_IDENTITY = 276,
    TK_IDENTITY_VAL = 277,
    TK_DEST_MAC = 278,
    TK_MACADDRESS = 279,
    TK_SSID = 280,
    TK_SSID_VAL = 281,
    TK_EAP_TLS = 282,
    TK_USER_CERT = 283,
    TK_USER_KEY = 284,
    TK_USER_KEY_PASS = 285,
    TK_SESSION_RESUME = 286,
    TK_CNCHECK = 287,
    TK_CNEXACT = 288,
    TK_ROOT_CERT = 289,
    TK_ROOT_DIR = 290,
    TK_CRL_DIR = 291,
    TK_CHUNK_SIZE = 292,
    TK_RANDOM_FILE = 293,
    TK_EAP_MD5 = 294,
    TK_USERNAME = 295,
    TK_USERNAME_VAL = 296,
    TK_PASSWORD = 297,
    TK_EAP_LEAP = 298,
    TK_EAP_TTLS = 299,
    TK_PHASE2_TYPE = 300,
    TK_PAP = 301,
    TK_CHAP = 302,
    TK_MSCHAP = 303,
    TK_MSCHAPV2 = 304,
    TK_EAP_MSCHAPV2 = 305,
    TK_EAP_PEAP = 306,
    TK_EAP_SIM = 307,
    TK_AUTO_REALM = 308,
    TK_YES = 309,
    TK_NO = 310,
    TK_EAP_GTC = 311,
    TK_EAP_OTP = 312,
    TK_NUMBER = 313,
    TK_FNAME = 314,
    TK_PASS = 315,
    TK_COMMAND = 316
  };
#endif
/* Tokens.  */
#define TK_NETWORK_LIST 258
#define TK_DEFAULT_NETNAME 259
#define TK_NETNAME 260
#define TK_STARTUP_COMMAND 261
#define TK_FIRST_AUTH_COMMAND 262
#define TK_REAUTH_COMMAND 263
#define TK_LOGFILE 264
#define TK_AUTH_PERIOD 265
#define TK_HELD_PERIOD 266
#define TK_MAX_STARTS 267
#define TK_ALLOW_INTERFACES 268
#define TK_DENY_INTERFACES 269
#define TK_ALL 270
#define TK_TYPE 271
#define TK_ALLOW_TYPES 272
#define TK_WIRELESS 273
#define TK_WIRED 274
#define TK_CONTROL_WIRELESS 275
#define TK_IDENTITY 276
#define TK_IDENTITY_VAL 277
#define TK_DEST_MAC 278
#define TK_MACADDRESS 279
#define TK_SSID 280
#define TK_SSID_VAL 281
#define TK_EAP_TLS 282
#define TK_USER_CERT 283
#define TK_USER_KEY 284
#define TK_USER_KEY_PASS 285
#define TK_SESSION_RESUME 286
#define TK_CNCHECK 287
#define TK_CNEXACT 288
#define TK_ROOT_CERT 289
#define TK_ROOT_DIR 290
#define TK_CRL_DIR 291
#define TK_CHUNK_SIZE 292
#define TK_RANDOM_FILE 293
#define TK_EAP_MD5 294
#define TK_USERNAME 295
#define TK_USERNAME_VAL 296
#define TK_PASSWORD 297
#define TK_EAP_LEAP 298
#define TK_EAP_TTLS 299
#define TK_PHASE2_TYPE 300
#define TK_PAP 301
#define TK_CHAP 302
#define TK_MSCHAP 303
#define TK_MSCHAPV2 304
#define TK_EAP_MSCHAPV2 305
#define TK_EAP_PEAP 306
#define TK_EAP_SIM 307
#define TK_AUTO_REALM 308
#define TK_YES 309
#define TK_NO 310
#define TK_EAP_GTC 311
#define TK_EAP_OTP 312
#define TK_NUMBER 313
#define TK_FNAME 314
#define TK_PASS 315
#define TK_COMMAND 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 331 "config_grammar.y" /* yacc.c:355  */

        char    *str;
        int     num;

#line 563 "config_grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 580 "config_grammar.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  186
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  365

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    65,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   403,   403,   407,   411,   416,   421,   422,   425,   426,
     429,   434,   437,   445,   453,   461,   469,   480,   487,   494,
     501,   504,   509,   519,   531,   547,   565,   581,   599,   620,
     621,   622,   623,   627,   628,   629,   630,   631,   632,   635,
     641,   649,   655,   663,   673,   683,   709,   714,   717,   729,
     740,   751,   762,   773,   784,   797,   798,   801,   806,   811,
     816,   821,   826,   831,   836,   841,   848,   849,   854,   855,
     858,   866,   874,   882,   888,   894,   902,   910,   918,   924,
     934,   935,   940,   941,   944,   952,   962,   963,   968,   969,
     972,   980,   988,   996,  1004,  1012,  1020,  1026,  1034,  1040,
    1046,  1054,  1059,  1064,  1074,  1084,  1094,  1104,  1114,  1117,
    1118,  1119,  1120,  1121,  1124,  1137,  1138,  1141,  1149,  1159,
    1172,  1173,  1176,  1184,  1194,  1207,  1208,  1211,  1219,  1230,
    1243,  1244,  1247,  1255,  1264,  1277,  1278,  1283,  1284,  1287,
    1295,  1305,  1306,  1311,  1312,  1315,  1323,  1333,  1334,  1339,
    1340,  1343,  1351,  1359,  1367,  1375,  1383,  1391,  1399,  1405,
    1411,  1417,  1425,  1430,  1435,  1443,  1444,  1447,  1452,  1455,
    1456,  1459,  1464,  1469,  1474,  1479,  1487,  1498,  1509,  1522,
    1523,  1528,  1529,  1532,  1540,  1548,  1553
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NETWORK_LIST", "TK_DEFAULT_NETNAME",
  "TK_NETNAME", "TK_STARTUP_COMMAND", "TK_FIRST_AUTH_COMMAND",
  "TK_REAUTH_COMMAND", "TK_LOGFILE", "TK_AUTH_PERIOD", "TK_HELD_PERIOD",
  "TK_MAX_STARTS", "TK_ALLOW_INTERFACES", "TK_DENY_INTERFACES", "TK_ALL",
  "TK_TYPE", "TK_ALLOW_TYPES", "TK_WIRELESS", "TK_WIRED",
  "TK_CONTROL_WIRELESS", "TK_IDENTITY", "TK_IDENTITY_VAL", "TK_DEST_MAC",
  "TK_MACADDRESS", "TK_SSID", "TK_SSID_VAL", "TK_EAP_TLS", "TK_USER_CERT",
  "TK_USER_KEY", "TK_USER_KEY_PASS", "TK_SESSION_RESUME", "TK_CNCHECK",
  "TK_CNEXACT", "TK_ROOT_CERT", "TK_ROOT_DIR", "TK_CRL_DIR",
  "TK_CHUNK_SIZE", "TK_RANDOM_FILE", "TK_EAP_MD5", "TK_USERNAME",
  "TK_USERNAME_VAL", "TK_PASSWORD", "TK_EAP_LEAP", "TK_EAP_TTLS",
  "TK_PHASE2_TYPE", "TK_PAP", "TK_CHAP", "TK_MSCHAP", "TK_MSCHAPV2",
  "TK_EAP_MSCHAPV2", "TK_EAP_PEAP", "TK_EAP_SIM", "TK_AUTO_REALM",
  "TK_YES", "TK_NO", "TK_EAP_GTC", "TK_EAP_OTP", "TK_NUMBER", "TK_FNAME",
  "TK_PASS", "TK_COMMAND", "'='", "','", "'{'", "'}'", "$accept",
  "configfile", "global_section", "network_section", "global_statement",
  "network_list", "allow_interface_list", "deny_interface_list",
  "network_entry", "network_statements", "network_parameter",
  "network_type_parameter", "network_control_wireless",
  "network_identity_parameter", "network_ssid_parameter",
  "network_dest_mac_parameter", "network_allow_parameter",
  "eap_type_statement", "eap_type_list", "eap_type", "eap_tls_statement",
  "eap_tls_params", "eap_tls_param", "eap_md5_statement", "eap_md5_params",
  "eap_md5_param", "eap_ttls_statement", "eap_ttls_params",
  "eap_ttls_param", "eap_ttls_phase2_statement", "phase2_pap_statement",
  "phase2_pap_params", "phase2_pap_param", "phase2_chap_statement",
  "phase2_chap_params", "phase2_chap_param", "phase2_mschap_statement",
  "phase2_mschap_params", "phase2_mschap_param",
  "phase2_mschapv2_statement", "phase2_mschapv2_params",
  "phase2_mschapv2_param", "eap_ttls_phase2_eap_statement",
  "eap_leap_statement", "eap_leap_params", "eap_leap_param",
  "eap_mschapv2_statement", "eap_mschapv2_params", "eap_mschapv2_param",
  "eap_peap_statement", "eap_peap_params", "eap_peap_param",
  "eap_peap_allow_parameter", "eap_peap_phase2_type_list",
  "eap_peap_phase2_type", "eap_peap_phase2_statement", "eap_sim_statement",
  "eap_sim_params", "eap_sim_param", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    61,    44,   123,   125
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     271,   -91,   -48,   -41,   -31,    -3,     2,     4,     8,    12,
      30,    32,    44,    48,    76,   283,   110,   -91,   -91,    11,
     118,   186,    87,    89,    91,   128,   114,   126,   127,   191,
     207,   -91,   110,   -91,   -91,   -91,   -91,   156,   -91,   153,
     161,   164,   165,   169,   173,   177,   185,   187,   194,   195,
     196,   197,   -12,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   193,   -91,   199,   258,
      10,    78,   -18,   242,   243,   240,   152,    31,    35,   108,
     109,    13,   -30,   -91,   -91,   -91,   263,   265,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   235,   -91,   -91,   -91,   -91,   -91,   -91,   209,   237,
     238,   239,   241,   244,   245,   246,   247,   -91,   163,   -91,
     248,   249,   -91,   174,   -91,   250,   251,   -91,   178,   -91,
     252,   253,   254,   255,   256,   257,   259,   260,   261,   262,
     264,   266,   267,   268,   269,   270,   -91,   -91,   130,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   273,   274,   -91,   182,
     -91,   275,   276,   277,   278,   279,   280,   281,   282,   284,
     285,   286,   287,   288,   -91,   -91,   -91,    51,   -91,   -91,
     -91,   -91,   289,   290,   291,   -91,   168,   -91,   -91,   -91,
      68,   295,   296,   297,     7,   299,   300,   301,   272,   302,
     -91,   -91,   304,   303,   -91,   -91,   315,   305,   -91,   -91,
     307,   308,   309,    59,   311,    72,   312,   313,   314,   306,
     316,   206,   -23,    14,    15,    18,   -91,   -91,   321,   317,
     -91,   -91,    52,   298,   319,   320,   322,    77,   324,   116,
     325,   326,   327,   310,   328,   -91,   -91,   333,   329,   150,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   318,   330,   192,   -91,   331,
     332,   200,   -91,   334,   335,   204,   -91,   336,   337,   208,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   338,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   340,
     342,   -91,   -91,   347,   343,   -91,   -91,   349,   344,   -91,
     -91,   350,   345,   -91,   -91,   -32,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     7,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     6,     8,    23,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    33,    38,    34,    36,    35,    37,
      32,    48,    49,    50,    51,    52,    53,    54,    13,    14,
      15,    16,    17,    18,    19,    25,    20,    27,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,     0,     0,    22,    39,
      40,    46,    57,    58,    60,    59,    61,    62,    63,    64,
      65,    47,    56,    41,    42,    43,    45,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    69,
       0,     0,    81,     0,    83,     0,     0,   136,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,   134,     0,    89,
     108,   109,   110,   111,   112,   113,     0,     0,   142,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   177,   176,     0,   150,   165,
     166,   178,     0,     0,     0,   180,     0,   182,    24,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    68,     0,     0,    80,    82,     0,     0,   135,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    88,     0,     0,
     141,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   149,     0,     0,     0,
     179,   181,    55,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    84,    85,   139,   140,    90,    91,    92,
      98,    99,   100,   101,   102,    93,    94,    95,    96,    97,
     107,   103,   104,   105,   106,     0,     0,     0,   116,     0,
       0,     0,   121,     0,     0,     0,   126,     0,     0,     0,
     131,   145,   146,   167,   172,   171,   173,   175,   174,   168,
     170,   151,   152,   153,   154,   158,   159,   161,   162,   163,
     155,   156,   157,   160,   164,   183,   184,   185,   186,     0,
       0,   114,   115,     0,     0,   119,   120,     0,     0,   124,
     125,     0,     0,   129,   130,     0,   117,   118,   122,   123,
     127,   128,   132,   133,   169
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   361,   380,   -91,   -91,   -91,   -10,   -91,
     348,   -91,   -91,   -91,   -91,   -91,   -91,   354,   -91,   102,
     -91,   -91,   176,   -89,   -91,   172,   -91,   -91,   167,   -91,
     -91,   -91,   111,   -91,   -91,    26,   -91,   -91,    24,   -91,
     -91,    98,   -91,   -91,   -91,   292,   -90,   -91,   293,   -91,
     -91,   222,   -91,   -91,    55,   -91,   -88,   -91,   215
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    37,    76,    78,    18,    52,
      53,    54,    55,    56,    57,    58,    59,    60,   111,   112,
      61,   128,   129,    62,   133,   134,    63,   158,   159,   160,
     161,   297,   298,   162,   301,   302,   163,   305,   306,   164,
     309,   310,   165,    64,   138,   139,    65,   169,   170,    66,
     187,   188,   189,   319,   320,   190,    67,   196,   197
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     157,   186,   185,   191,    39,    40,    34,   314,    41,    42,
     192,    43,   193,    44,    19,    45,    35,   295,   315,   296,
     316,    20,    34,   194,   317,   318,    36,    46,    99,   100,
     171,    47,    48,    21,   172,   195,   113,   114,    49,    50,
      51,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    46,    93,   299,   303,   300,   304,   307,    22,
     308,   266,   267,    49,    23,    51,    24,   313,   171,   157,
      25,   130,   172,   131,    26,   135,    31,   136,   184,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      46,   314,    27,   101,    28,   102,   132,   186,   185,   191,
     137,    49,   315,    51,   316,   102,    29,   103,   317,   318,
      30,   104,   105,   280,   281,     4,   255,   103,   106,   107,
     108,   104,   105,    38,   109,   110,   283,   284,   106,   107,
     108,   325,   326,    71,   109,   110,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    46,    68,   166,
      69,   167,    70,   151,   152,   153,   154,   155,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    46,
     328,   329,    72,   156,   168,   151,   152,   153,   154,   155,
     118,   119,   120,   121,    73,    74,   122,   123,   124,   125,
     126,   118,   119,   120,   121,   236,    75,   122,   123,   124,
     125,   126,    39,    40,   337,   338,    41,    42,   192,    43,
     193,    44,    77,    45,   130,    80,   131,   127,   135,    79,
     136,   194,   166,    81,   167,    46,    82,    83,   210,    47,
      48,    84,   295,   260,   296,    85,    49,    50,    51,   214,
     299,    86,   300,   218,   303,   290,   304,   240,   307,    87,
     308,    88,   291,   292,   293,   294,    96,   341,    89,    90,
      91,    92,    97,    98,   115,   345,   117,   116,   198,   349,
     199,   201,     1,   353,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,   200,   202,
     203,   204,   262,   205,   211,   215,   206,   207,   208,   209,
     212,   213,   216,   217,   220,   221,   222,   223,   224,   225,
     321,   226,   227,   228,   229,   237,   230,   346,   231,   350,
     271,   232,   233,   234,   235,   238,   239,   242,   243,   244,
     245,   246,   247,   248,   249,   273,   250,   251,   252,   253,
     254,   257,   258,   259,   263,   264,   275,   265,   268,   269,
     270,   272,   311,   274,   288,   276,   277,   278,   333,   279,
     282,   285,   286,   287,   335,   289,    32,   312,   322,   323,
     339,   356,   324,   327,   330,   331,   332,   334,   358,   336,
     360,   362,   340,   343,   344,    33,   347,   348,   351,   352,
      94,   355,   357,   359,   361,   363,    95,   354,   342,   256,
     364,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241
};

static const yytype_int16 yycheck[] =
{
      89,    91,    91,    91,    16,    17,    16,    39,    20,    21,
      40,    23,    42,    25,    62,    27,     5,    40,    50,    42,
      52,    62,    32,    53,    56,    57,    15,    39,    18,    19,
      17,    43,    44,    64,    21,    65,    54,    55,    50,    51,
      52,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    65,    40,    40,    42,    42,    40,    62,
      42,    54,    55,    50,    62,    52,    62,    15,    17,   158,
      62,    40,    21,    42,    62,    40,     0,    42,    65,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    39,    62,    15,    62,    27,    65,   187,   187,   187,
      65,    50,    50,    52,    52,    27,    62,    39,    56,    57,
      62,    43,    44,    54,    55,     5,    65,    39,    50,    51,
      52,    43,    44,     5,    56,    57,    54,    55,    50,    51,
      52,    54,    55,     5,    56,    57,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    61,    40,
      61,    42,    61,    45,    46,    47,    48,    49,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      54,    55,    58,    65,    65,    45,    46,    47,    48,    49,
      28,    29,    30,    31,    58,    58,    34,    35,    36,    37,
      38,    28,    29,    30,    31,    65,     5,    34,    35,    36,
      37,    38,    16,    17,    54,    55,    20,    21,    40,    23,
      42,    25,     5,    27,    40,    62,    42,    65,    40,    63,
      42,    53,    40,    62,    42,    39,    62,    62,    65,    43,
      44,    62,    40,    65,    42,    62,    50,    51,    52,    65,
      40,    64,    42,    65,    40,    39,    42,    65,    40,    64,
      42,    64,    46,    47,    48,    49,    63,    65,    64,    64,
      64,    64,    63,     5,    22,    65,    26,    24,     5,    65,
       5,    62,     1,    65,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    63,    62,
      62,    62,   200,    62,   128,   133,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      22,    62,    62,    62,    62,   158,    62,   301,    62,   305,
      58,    64,    64,    64,    64,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    41,    62,    62,    62,    62,
      62,    62,    62,    62,    59,    59,    41,    60,    59,    59,
      59,    59,    41,    60,    58,    60,    59,    59,    58,    60,
      59,    59,    59,    59,    41,    59,    15,    60,    59,    59,
      62,    41,    60,    59,    59,    59,    59,    59,    41,    60,
      41,    41,    62,    62,    62,    15,    62,    62,    62,    62,
      52,    63,    60,    60,    60,    60,    52,   309,   297,   187,
     355,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    67,    68,    69,    70,    74,    62,
      62,    64,    62,    62,    62,    62,    62,    62,    62,    62,
      62,     0,    69,    70,    74,     5,    15,    71,     5,    16,
      17,    20,    21,    23,    25,    27,    39,    43,    44,    50,
      51,    52,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    86,    89,    92,   109,   112,   115,   122,    61,    61,
      61,     5,    58,    58,    58,     5,    72,     5,    73,    63,
      62,    62,    62,    62,    62,    62,    64,    64,    64,    64,
      64,    64,    64,    65,    76,    83,    63,    63,     5,    18,
      19,    15,    27,    39,    43,    44,    50,    51,    52,    56,
      57,    84,    85,    54,    55,    22,    24,    26,    28,    29,
      30,    31,    34,    35,    36,    37,    38,    65,    87,    88,
      40,    42,    65,    90,    91,    40,    42,    65,   110,   111,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    45,    46,    47,    48,    49,    65,    89,    93,    94,
      95,    96,    99,   102,   105,   108,    40,    42,    65,   113,
     114,    17,    21,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    65,    89,   112,   116,   117,   118,
     121,   122,    40,    42,    53,    65,   123,   124,     5,     5,
      63,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      65,    88,    62,    62,    65,    91,    62,    62,    65,   111,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    64,    64,    64,    64,    65,    94,    62,    62,
      65,   114,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    65,   117,    62,    62,    62,
      65,   124,    85,    59,    59,    60,    54,    55,    59,    59,
      59,    58,    59,    41,    60,    41,    60,    59,    59,    60,
      54,    55,    59,    54,    55,    59,    59,    59,    58,    59,
      39,    46,    47,    48,    49,    40,    42,    97,    98,    40,
      42,   100,   101,    40,    42,   103,   104,    40,    42,   106,
     107,    41,    60,    15,    39,    50,    52,    56,    57,   119,
     120,    22,    59,    59,    60,    54,    55,    59,    54,    55,
      59,    59,    59,    58,    59,    41,    60,    54,    55,    62,
      62,    65,    98,    62,    62,    65,   101,    62,    62,    65,
     104,    62,    62,    65,   107,    63,    41,    60,    41,    60,
      41,    60,    41,    60,   120
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    80,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    96,    97,    97,    98,    98,    99,
     100,   100,   101,   101,   102,   103,   103,   104,   104,   105,
     106,   106,   107,   107,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   120,   120,   120,   121,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   124
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     2,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     1,     4,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     2,     1,     3,     3,     4,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     4,     2,     1,     3,     3,     4,
       2,     1,     3,     3,     4,     2,     1,     3,     3,     4,
       2,     1,     3,     3,     1,     4,     3,     2,     1,     3,
       3,     4,     3,     2,     1,     3,     3,     4,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     2,     1,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 403 "config_grammar.y" /* yacc.c:1646  */
    {
		     config_info = tmp_config; 
		     tmp_config = NULL;
                  }
#line 1958 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 407 "config_grammar.y" /* yacc.c:1646  */
    { 
                      debug_printf(DEBUG_NORMAL, "Error: No networks defined.\n"); 
		      CLEAN_EXIT;
		    }
#line 1967 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 411 "config_grammar.y" /* yacc.c:1646  */
    {
		      debug_printf(DEBUG_NORMAL, "Error: No globals defined.\n"); 
		      cleanup_parse();
		      return XECONFIGPARSEFAIL;
                    }
#line 1977 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 416 "config_grammar.y" /* yacc.c:1646  */
    {
 		      cleanup_parse();
		      return XECONFIGPARSEFAIL; }
#line 1985 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 10:
#line 429 "config_grammar.y" /* yacc.c:1646  */
    {
                      set_current_globals();
                      parameter_debug("network_list: all\n");
		      // do nothing. leave null
                    }
#line 1995 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 434 "config_grammar.y" /* yacc.c:1646  */
    {
		    // done below. nothing to do here
  		    }
#line 2003 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 437 "config_grammar.y" /* yacc.c:1646  */
    {
 		     set_current_globals();
		     parameter_debug("Default network: \"%s\"\n", (yyvsp[0].str));
		     if (tmp_config->globals->default_net)
		       free((yyvsp[0].str));
		     else
		       tmp_config->globals->default_net = (yyvsp[0].str);
		  }
#line 2016 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 13:
#line 445 "config_grammar.y" /* yacc.c:1646  */
    {
 		     set_current_globals();
		     parameter_debug("Startup command: \"%s\"\n", (yyvsp[0].str));
		     if (tmp_config->globals->startup_command)
		       free((yyvsp[0].str));
		     else
		       tmp_config->globals->startup_command = (yyvsp[0].str);
		    }
#line 2029 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 14:
#line 453 "config_grammar.y" /* yacc.c:1646  */
    {
 		     set_current_globals();
		     parameter_debug("First_Auth command: \"%s\"\n", (yyvsp[0].str));
		     if (tmp_config->globals->first_auth_command)
		       free((yyvsp[0].str));
		     else
		       tmp_config->globals->first_auth_command = (yyvsp[0].str);
		    }
#line 2042 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 15:
#line 461 "config_grammar.y" /* yacc.c:1646  */
    {
 		     set_current_globals();
		     parameter_debug("Reauth command: \"%s\"\n", (yyvsp[0].str));
		     if (tmp_config->globals->reauth_command)
		       free((yyvsp[0].str));
		     else
		       tmp_config->globals->reauth_command = (yyvsp[0].str);
		    }
#line 2055 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 16:
#line 469 "config_grammar.y" /* yacc.c:1646  */
    {
		     set_current_globals();
		     parameter_debug("Logfile: \"%s\"\n", (yyvsp[0].str));
		     if (tmp_config->globals->logfile)
		       {
			 free((yyvsp[0].str));
			 tmp_config->globals->logfile = NULL;
		       }
		     else
		       tmp_config->globals->logfile = (yyvsp[0].str);
		    }
#line 2071 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 480 "config_grammar.y" /* yacc.c:1646  */
    {
		     set_current_globals();
		     if (!TEST_FLAG(tmp_config->globals->flags, CONFIG_GLOBALS_AUTH_PER)) {
		       SET_FLAG(tmp_config->globals->flags, CONFIG_GLOBALS_AUTH_PER);
		       tmp_config->globals->auth_period = (yyvsp[0].num);
		     }
                    }
#line 2083 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 487 "config_grammar.y" /* yacc.c:1646  */
    {
		     set_current_globals();
		     if (!TEST_FLAG(tmp_config->globals->flags, CONFIG_GLOBALS_HELD_PER)) {
		       SET_FLAG(tmp_config->globals->flags, CONFIG_GLOBALS_HELD_PER);
		       tmp_config->globals->held_period = (yyvsp[0].num);
		     }
                    }
#line 2095 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 19:
#line 494 "config_grammar.y" /* yacc.c:1646  */
    {
		     set_current_globals();
		     if (!TEST_FLAG(tmp_config->globals->flags, CONFIG_GLOBALS_MAX_STARTS)) {
		       SET_FLAG(tmp_config->globals->flags, CONFIG_GLOBALS_MAX_STARTS);
		       tmp_config->globals->max_starts = (yyvsp[0].num);
		     }
                    }
#line 2107 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 20:
#line 501 "config_grammar.y" /* yacc.c:1646  */
    {
                     // nothing to do here
                    }
#line 2115 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 504 "config_grammar.y" /* yacc.c:1646  */
    {
                     // nothing to do here
                    }
#line 2123 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 509 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("network_list: \"%s\"\n", (yyvsp[0].str));
		       set_current_globals();
		       if (config_string_list_contains_string(tmp_config->globals->allowed_nets,
							    (yyvsp[0].str)))
			 free((yyvsp[0].str));
		       else 
			 config_string_list_add_string(&tmp_config->globals->allowed_nets,
						     (yyvsp[0].str));
                    }
#line 2138 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 519 "config_grammar.y" /* yacc.c:1646  */
    { 
                       parameter_debug("network_list: \"%s\"\n", (yyvsp[0].str));
		       set_current_globals();
		       if (config_string_list_contains_string(tmp_config->globals->allowed_nets,
							    (yyvsp[0].str)))
			 free((yyvsp[0].str));
		       else 
			 config_string_list_add_string(&tmp_config->globals->allowed_nets,
						     (yyvsp[0].str));
                    }
#line 2153 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 531 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("allow_interface_list: \"%s\"\n", (yyvsp[0].str));
		       set_current_globals();
		       if (config_string_list_contains_string(tmp_config->globals->allow_interfaces,
							      (yyvsp[0].str)))
			 free((yyvsp[0].str));
		       else if (config_string_list_contains_string(tmp_config->globals->deny_interfaces,
								   (yyvsp[0].str))) {
			 debug_printf(DEBUG_NORMAL,
				      "Interface \"%s\" both allowed and denied\n", (yyvsp[0].str));
			 CLEAN_EXIT;
		       }
		       else 
			 config_string_list_add_string(&tmp_config->globals->allow_interfaces,
						     (yyvsp[0].str));
                    }
#line 2174 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 25:
#line 547 "config_grammar.y" /* yacc.c:1646  */
    { 
                       parameter_debug("allow_interface_list: \"%s\"\n", (yyvsp[0].str));
		       set_current_globals();
		       if (config_string_list_contains_string(tmp_config->globals->allow_interfaces,
							    (yyvsp[0].str)))
			 free((yyvsp[0].str));
		       else if (config_string_list_contains_string(tmp_config->globals->deny_interfaces,
								   (yyvsp[0].str))) {
			 debug_printf(DEBUG_NORMAL,
				      "Interface \"%s\" both allowed and denied\n", (yyvsp[0].str));
			 CLEAN_EXIT;
		       }
		       else 
			 config_string_list_add_string(&tmp_config->globals->allow_interfaces,
						     (yyvsp[0].str));
                    }
#line 2195 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 26:
#line 565 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("deny_interface_list: \"%s\"\n", (yyvsp[0].str));
		       set_current_globals();
		       if (config_string_list_contains_string(tmp_config->globals->deny_interfaces,
							      (yyvsp[0].str)))
			 free((yyvsp[0].str));
		       else if (config_string_list_contains_string(tmp_config->globals->allow_interfaces,
								   (yyvsp[0].str))) {
			 debug_printf(DEBUG_NORMAL,
				      "Interface \"%s\" both allowed and denied\n", (yyvsp[0].str));
			 CLEAN_EXIT;
		       }
		       else 
			 config_string_list_add_string(&tmp_config->globals->deny_interfaces,
						     (yyvsp[0].str));
                    }
#line 2216 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 27:
#line 581 "config_grammar.y" /* yacc.c:1646  */
    { 
                       parameter_debug("deny_interface_list: \"%s\"\n", (yyvsp[0].str));
		       set_current_globals();
		       if (config_string_list_contains_string(tmp_config->globals->deny_interfaces,
							    (yyvsp[0].str)))
			 free((yyvsp[0].str));
		       else if (config_string_list_contains_string(tmp_config->globals->allow_interfaces,
								   (yyvsp[0].str))) {
			 debug_printf(DEBUG_NORMAL,
				      "Interface \"%s\" both allowed and denied\n", (yyvsp[0].str));
			 CLEAN_EXIT;
		       }
		       else 
			 config_string_list_add_string(&tmp_config->globals->deny_interfaces,
						     (yyvsp[0].str));
                    }
#line 2237 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 28:
#line 599 "config_grammar.y" /* yacc.c:1646  */
    {
                      set_current_config();
		      tmp_network->name = (yyvsp[-3].str);
		      // check if there is a networks field and that 
		      // the current tmp is not already listed
		      if ((!tmp_config->networks ||
			  !config_network_contains_net(tmp_config->networks,
						       tmp_network->name)) &&
			  config_allows_network(tmp_config, tmp_network->name))
		      {
			config_network_add_net(&(tmp_config->networks),
					       tmp_network);
		      }
		      // if we don't need it, delete it
		      else {
			delete_config_network(&tmp_network);
		      }
		      tmp_network = NULL;
                    }
#line 2261 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 635 "config_grammar.y" /* yacc.c:1646  */
    {
                           parameter_debug("Type: Wireless\n");
			   set_current_network();
			   if (tmp_network->type == UNSET)
			     tmp_network->type = WIRELESS;
                         }
#line 2272 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 641 "config_grammar.y" /* yacc.c:1646  */
    {
                           parameter_debug("Type: Wired\n");
			   set_current_network();
			   if (tmp_network->type == UNSET)
			     tmp_network->type = WIRED;
                         }
#line 2283 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 649 "config_grammar.y" /* yacc.c:1646  */
    {
                           parameter_debug("Control Wireless = YES\n");
			   set_current_network();
			   if (tmp_network->wireless_ctrl == CTL_UNSET)
			     tmp_network->wireless_ctrl = CTL_YES;
                         }
#line 2294 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 655 "config_grammar.y" /* yacc.c:1646  */
    {
			   parameter_debug("Control Wireless = NO\n");
			   set_current_network();
			   if (tmp_network->wireless_ctrl == CTL_UNSET)
			     tmp_network->wireless_ctrl = CTL_NO;
			 }
#line 2305 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 663 "config_grammar.y" /* yacc.c:1646  */
    {
                            parameter_debug("ID: \"%s\"\n", (yyvsp[0].str));
			    set_current_network();
			    if (!tmp_network->identity)
			      tmp_network->identity = (yyvsp[0].str);
			    else
			      free((yyvsp[0].str));
                          }
#line 2318 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 673 "config_grammar.y" /* yacc.c:1646  */
    {
                            parameter_debug("SSID: \"%s\"\n", (yyvsp[0].str));
			    set_current_network();
			    if (!tmp_network->ssid)
			      tmp_network->ssid = (yyvsp[0].str);
			    else
			      free((yyvsp[0].str));
                         }
#line 2331 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 45:
#line 683 "config_grammar.y" /* yacc.c:1646  */
    {
                            parameter_debug("Dest Mac: %s\n", (yyvsp[0].str));
			    set_current_network();
			    if (TEST_FLAG(tmp_network->flags, CONFIG_NET_DEST_MAC)) {
			      free((yyvsp[0].str));
			    }
			    else {
			      int tmp_dst_mac[CONFIG_MAC_LEN];
			      SET_FLAG(tmp_network->flags, CONFIG_NET_DEST_MAC);
			      sscanf((yyvsp[0].str), "%2x:%2x:%2x:%2x:%2x:%2x", 
				     &tmp_dst_mac[0], 
				     &tmp_dst_mac[1], 
				     &tmp_dst_mac[2], 
				     &tmp_dst_mac[3], 
				     &tmp_dst_mac[4], 
				     &tmp_dst_mac[5]);
			      tmp_network->dest_mac[0] = tmp_dst_mac[0];
			      tmp_network->dest_mac[1] = tmp_dst_mac[1];
			      tmp_network->dest_mac[2] = tmp_dst_mac[2];
			      tmp_network->dest_mac[3] = tmp_dst_mac[3];
			      tmp_network->dest_mac[4] = tmp_dst_mac[4];
			      tmp_network->dest_mac[5] = tmp_dst_mac[5];
			    }
                         }
#line 2360 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 709 "config_grammar.y" /* yacc.c:1646  */
    {
                           parameter_debug("Allow Types: ALL\n");
			   set_current_network();
			   SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_ALL);
                       }
#line 2370 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 717 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_network(); 
		       if (!config_eap_method_contains_method(tmp_network->methods,
							      EAP_TYPE_TLS)) {
			 add_config_eap_method(&(tmp_network->methods),
					       EAP_TYPE_TLS,
					       tmp_tls);
		       }
		       else 
			 delete_config_eap_tls(&tmp_tls);
		       tmp_tls = NULL;
                      }
#line 2387 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 729 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_network(); 
		       if (!config_eap_method_contains_method(tmp_network->methods,
							      EAP_TYPE_MD5))
			 add_config_eap_method(&(tmp_network->methods),
					       EAP_TYPE_MD5,
					       tmp_md5);
		       else 
			 delete_config_eap_md5(&tmp_md5);
		       tmp_md5 = NULL;
                      }
#line 2403 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 50:
#line 740 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_network(); 
		       if (!config_eap_method_contains_method(tmp_network->methods,
							      EAP_TYPE_TTLS))
			 add_config_eap_method(&(tmp_network->methods),
					       EAP_TYPE_TTLS,
					       tmp_ttls);
		       else 
			 delete_config_eap_ttls(&tmp_ttls);
		       tmp_ttls = NULL;
                      }
#line 2419 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 751 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_network(); 
		       if (!config_eap_method_contains_method(tmp_network->methods,
							      EAP_TYPE_LEAP))
			 add_config_eap_method(&(tmp_network->methods),
					       EAP_TYPE_LEAP,
					       tmp_leap);
		       else 
			 delete_config_eap_leap(&tmp_leap);
		       tmp_leap = NULL;
                      }
#line 2435 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 762 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_network(); 
		       if (!config_eap_method_contains_method(tmp_network->methods,
							      EAP_TYPE_MSCHAPV2))
			 add_config_eap_method(&(tmp_network->methods),
					       EAP_TYPE_MSCHAPV2,
					       tmp_mschapv2);
		       else 
			 delete_config_eap_mschapv2(&tmp_mschapv2);
		       tmp_mschapv2 = NULL;
                      }
#line 2451 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 773 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_network(); 
		       if (!config_eap_method_contains_method(tmp_network->methods,
							      EAP_TYPE_PEAP))
			 add_config_eap_method(&(tmp_network->methods),
					       EAP_TYPE_PEAP,
					       tmp_peap);
		       else 
			 delete_config_eap_peap(&tmp_peap);
		       tmp_peap = NULL;
                      }
#line 2467 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 54:
#line 784 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_network(); 
		       if (!config_eap_method_contains_method(tmp_network->methods,
							      EAP_TYPE_SIM))
			 add_config_eap_method(&(tmp_network->methods),
					       EAP_TYPE_SIM,
					       tmp_sim);
		       else 
			 delete_config_eap_sim(&tmp_sim);
		       tmp_sim = NULL;
                      }
#line 2483 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 57:
#line 801 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: TLS\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_TLS);
                      }
#line 2493 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 806 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: MD5\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_MD5);
                      }
#line 2503 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 59:
#line 811 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: TTLS\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_TTLS);
                      }
#line 2513 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 816 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: LEAP\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_LEAP);
                      }
#line 2523 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 821 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: MSCHAPV2\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_MSCV2);
                      }
#line 2533 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 62:
#line 826 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: PEAP\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_PEAP);
                      }
#line 2543 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 831 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: SIM\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_SIM);
                      }
#line 2553 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 836 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: GTC\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_GTC);
                      }
#line 2563 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 65:
#line 841 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("Allow Type: OTP\n");
			set_current_network();
			SET_FLAG(tmp_network->flags, CONFIG_NET_ALLOW_OTP);
                      }
#line 2573 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 849 "config_grammar.y" /* yacc.c:1646  */
    {
                        set_current_tls(); /* define an empty tls struct*/
                      }
#line 2581 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 858 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("tls user cert: \"%s\"\n", (yyvsp[0].str));
			set_current_tls();
			if (!tmp_tls->user_cert)
			  tmp_tls->user_cert = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
                      }
#line 2594 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 866 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("tls user key: \"%s\"\n", (yyvsp[0].str));
			set_current_tls();
			if (!tmp_tls->user_key)
			  tmp_tls->user_key = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 2607 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 874 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("tls user pass: \"%s\"\n", (yyvsp[0].str));
			set_current_tls();
			if (!tmp_tls->user_key_pass)
			  tmp_tls->user_key_pass = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
        	      }
#line 2620 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 73:
#line 882 "config_grammar.y" /* yacc.c:1646  */
    {
		        parameter_debug("Session Resumption = YES\n");
		        set_current_tls();
		        if (tmp_tls->session_resume == RES_UNSET)
			  tmp_tls->session_resume = RES_YES;
		      }
#line 2631 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 888 "config_grammar.y" /* yacc.c:1646  */
    {
			parameter_debug("Session Resumption = NO\n");
			set_current_tls();
			if (tmp_tls->session_resume == RES_UNSET)
			  tmp_tls->session_resume = RES_NO;
		      }
#line 2642 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 894 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("tls root_cert: \"%s\"\n", (yyvsp[0].str));
			set_current_tls();
			if (!tmp_tls->root_cert)
			  tmp_tls->root_cert = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
        	      }
#line 2655 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 902 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("tls root_dir: \"%s\"\n", (yyvsp[0].str));
			set_current_tls();
			if (!tmp_tls->root_dir)
			  tmp_tls->root_dir = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
        	      }
#line 2668 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 910 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("tls crl_dir: \"%s\"\n", (yyvsp[0].str));
			set_current_tls();
			if (!tmp_tls->crl_dir)
			  tmp_tls->crl_dir = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
        	      }
#line 2681 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 918 "config_grammar.y" /* yacc.c:1646  */
    {
 		        parameter_debug("tls chunk: %d\n", (yyvsp[0].num));
			set_current_tls();
			if (tmp_tls->chunk_size == 0)
			  tmp_tls->chunk_size = (yyvsp[0].num);
  		      }
#line 2692 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 924 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("tls rand: \"%s\"\n", (yyvsp[0].str));
			set_current_tls();
			if (!tmp_tls->random_file)
			  tmp_tls->random_file = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 2705 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 935 "config_grammar.y" /* yacc.c:1646  */
    {
                        set_current_md5(); /* define an empty md5 struct*/
                      }
#line 2713 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 944 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("md5 username: \"%s\"\n", (yyvsp[0].str));
		       set_current_md5();
		       if (!tmp_md5->username)
			 tmp_md5->username = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
                     }
#line 2726 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 952 "config_grammar.y" /* yacc.c:1646  */
    {
		       parameter_debug("md5 password: \"%s\"\n", (yyvsp[0].str));
		       set_current_md5();
		       if (!tmp_md5->password)
			 tmp_md5->password = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
		     }
#line 2739 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 963 "config_grammar.y" /* yacc.c:1646  */
    {
                        set_current_ttls(); /* define an empty ttls struct*/
                      }
#line 2747 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 90:
#line 972 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("ttls user cert: \"%s\"\n", (yyvsp[0].str));
			set_current_ttls();
			if (!tmp_ttls->user_cert)
			  tmp_ttls->user_cert = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
                      }
#line 2760 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 91:
#line 980 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls user key: \"%s\"\n", (yyvsp[0].str));
			set_current_ttls();
			if (!tmp_ttls->user_key)
			  tmp_ttls->user_key = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 2773 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 92:
#line 988 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls user pass: \"%s\"\n", (yyvsp[0].str));
			set_current_ttls();
			if (!tmp_ttls->user_key_pass)
			  tmp_ttls->user_key_pass = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
        	      }
#line 2786 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 93:
#line 996 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls root_cert: \"%s\"\n", (yyvsp[0].str));
			set_current_ttls();
			if (!tmp_ttls->root_cert)
			  tmp_ttls->root_cert = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
        	      }
#line 2799 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1004 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls root_dir: \"%s\"\n", (yyvsp[0].str));
			set_current_ttls();
			if (!tmp_ttls->root_dir)
			  tmp_ttls->root_dir = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 2812 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1012 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls crl_dir: \"%s\"\n", (yyvsp[0].str));
			set_current_ttls();
			if (!tmp_ttls->crl_dir)
			  tmp_ttls->crl_dir = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 2825 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1020 "config_grammar.y" /* yacc.c:1646  */
    {
 		        parameter_debug("ttls chunk: %d\n", (yyvsp[0].num));
			set_current_ttls();
			if (tmp_ttls->chunk_size == 0)
			  tmp_ttls->chunk_size = (yyvsp[0].num);
  		      }
#line 2836 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1026 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls rand: \"%s\"\n", (yyvsp[0].str));
			set_current_ttls();
			if (!tmp_ttls->random_file)
			  tmp_ttls->random_file = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 2849 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1034 "config_grammar.y" /* yacc.c:1646  */
    {
		        parameter_debug("Session Resumption = YES\n");
		        set_current_ttls();
		        if (tmp_ttls->session_resume == RES_UNSET)
			  tmp_ttls->session_resume = RES_YES;
		      }
#line 2860 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1040 "config_grammar.y" /* yacc.c:1646  */
    {
			parameter_debug("Session Resumption = NO\n");
			set_current_ttls();
			if (tmp_ttls->session_resume == RES_UNSET)
			  tmp_ttls->session_resume = RES_NO;
		      }
#line 2871 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1046 "config_grammar.y" /* yacc.c:1646  */
    {
		        parameter_debug("ttls CN check : \"%s\"\n", (yyvsp[0].str));
                        set_current_ttls();
                        if (!tmp_ttls->cncheck)
                          tmp_ttls->cncheck = (yyvsp[0].str);
                        else
                          free((yyvsp[0].str));
		      }
#line 2884 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1054 "config_grammar.y" /* yacc.c:1646  */
    {
  		        parameter_debug("match CN exactly : \"yes\"\n");
		        set_current_ttls();
		        tmp_ttls->cnexact = 1;
		    }
#line 2894 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1059 "config_grammar.y" /* yacc.c:1646  */
    {
  		        parameter_debug("match CN exactly : \"no\"\n");
		        set_current_ttls();
		        tmp_ttls->cnexact = 0;
		    }
#line 2904 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1064 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls phase2_type 'pap'\n");
			if (tmp_ttls && 
			    tmp_ttls->phase2_type != TTLS_PHASE2_UNDEFINED) {
			  cleanup_parse();
			  return XECONFIGPARSEFAIL;  
			}
			set_current_ttls();
			tmp_ttls->phase2_type = TTLS_PHASE2_PAP;
        	      }
#line 2919 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1074 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls phase2_type 'chap'\n");
			if (tmp_ttls && 
			    tmp_ttls->phase2_type != TTLS_PHASE2_UNDEFINED) {
			  cleanup_parse();
			  return XECONFIGPARSEFAIL;  
			}
			set_current_ttls();
			tmp_ttls->phase2_type = TTLS_PHASE2_CHAP;
        	      }
#line 2934 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1084 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls phase2_type 'mschap'\n");
			if (tmp_ttls && 
			    tmp_ttls->phase2_type != TTLS_PHASE2_UNDEFINED) {
			  cleanup_parse();
			  return XECONFIGPARSEFAIL;  
			}
			set_current_ttls();
			tmp_ttls->phase2_type = TTLS_PHASE2_MSCHAP;
        	      }
#line 2949 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1094 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("ttls phase2_type 'mschapv2'\n");
			if (tmp_ttls && 
			    tmp_ttls->phase2_type != TTLS_PHASE2_UNDEFINED) {
			  cleanup_parse();
			  return XECONFIGPARSEFAIL;  
			}
			set_current_ttls();
			tmp_ttls->phase2_type = TTLS_PHASE2_MSCHAPV2;
        	      }
#line 2964 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1104 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("ttls phase2_type 'eap_md5'\n");
                        if (tmp_ttls &&
                            tmp_ttls->phase2_type != TTLS_PHASE2_UNDEFINED) {
                          cleanup_parse();
                          return XECONFIGPARSEFAIL;
                        }
                        set_current_ttls();
                        tmp_ttls->phase2_type = TTLS_PHASE2_EAP_MD5;
                     }
#line 2979 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1124 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_ttls(); 
		       if (!config_ttls_phase2_contains_phase2(tmp_ttls->phase2,
							       TTLS_PHASE2_PAP))
			 add_config_ttls_phase2(&(tmp_ttls->phase2), 
						TTLS_PHASE2_PAP,
						tmp_p2pap);
		       else
			 delete_config_pap(&tmp_p2pap);
		       tmp_p2pap = NULL;
                      }
#line 2995 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1141 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("pap username: \"%s\"\n", (yyvsp[0].str));
		       set_current_p2pap();
		       if (!tmp_p2pap->username)
			 tmp_p2pap->username = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
                     }
#line 3008 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1149 "config_grammar.y" /* yacc.c:1646  */
    {
		       parameter_debug("pap password: \"%s\"\n", (yyvsp[0].str));
		       set_current_p2pap();
		       if (!tmp_p2pap->password)
			 tmp_p2pap->password = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
		     }
#line 3021 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1159 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_ttls(); 
		       if (!config_ttls_phase2_contains_phase2(tmp_ttls->phase2,
							       TTLS_PHASE2_CHAP))
			 add_config_ttls_phase2(&(tmp_ttls->phase2), 
						TTLS_PHASE2_CHAP,
						tmp_p2chap);
		       else
			 delete_config_chap(&tmp_p2chap);
		       tmp_p2chap = NULL;
                      }
#line 3037 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1176 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("chap username: \"%s\"\n", (yyvsp[0].str));
		       set_current_p2chap();
		       if (!tmp_p2chap->username)
			 tmp_p2chap->username = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
                     }
#line 3050 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1184 "config_grammar.y" /* yacc.c:1646  */
    {
		       parameter_debug("chap password: \"%s\"\n", (yyvsp[0].str));
		       set_current_p2chap();
		       if (!tmp_p2chap->password)
			 tmp_p2chap->password = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
		     }
#line 3063 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1194 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_ttls(); 
		       if (!config_ttls_phase2_contains_phase2(tmp_ttls->phase2,
							       TTLS_PHASE2_MSCHAP))
			 add_config_ttls_phase2(&(tmp_ttls->phase2), 
						TTLS_PHASE2_MSCHAP,
						tmp_p2mschap);
		       else
			 delete_config_mschap(&tmp_p2mschap);
		       tmp_p2mschap = NULL;
                      }
#line 3079 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1211 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("mschap username: \"%s\"\n", (yyvsp[0].str));
		       set_current_p2mschap();
		       if (!tmp_p2mschap->username)
			 tmp_p2mschap->username = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
                     }
#line 3092 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1219 "config_grammar.y" /* yacc.c:1646  */
    {
		       parameter_debug("mschap password: \"%s\"\n", (yyvsp[0].str));
		       set_current_p2mschap();
		       if (!tmp_p2mschap->password)
			 tmp_p2mschap->password = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
		     }
#line 3105 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1230 "config_grammar.y" /* yacc.c:1646  */
    {
                       set_current_ttls(); 
		       if (!config_ttls_phase2_contains_phase2(tmp_ttls->phase2,
							       TTLS_PHASE2_MSCHAPV2))
			 add_config_ttls_phase2(&(tmp_ttls->phase2), 
						TTLS_PHASE2_MSCHAPV2,
						tmp_p2mschapv2);
		       else
			 delete_config_mschapv2(&tmp_p2mschapv2);
		       tmp_p2mschapv2 = NULL;
                      }
#line 3121 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1247 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("mschapv2 username: \"%s\"\n", (yyvsp[0].str));
		       set_current_p2mschapv2();
		       if (!tmp_p2mschapv2->username)
			 tmp_p2mschapv2->username = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
                     }
#line 3134 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1255 "config_grammar.y" /* yacc.c:1646  */
    {
		       parameter_debug("mschapv2 password: \"%s\"\n", (yyvsp[0].str));
		       set_current_p2mschapv2();
		       if (!tmp_p2mschapv2->password)
			 tmp_p2mschapv2->password = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
		     }
#line 3147 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1264 "config_grammar.y" /* yacc.c:1646  */
    {
		       set_current_ttls();
		       if (!config_ttls_phase2_contains_phase2(tmp_ttls->phase2,
                                                                 TTLS_PHASE2_EAP_MD5))
		         add_config_ttls_phase2(&(tmp_ttls->phase2),
			  	  	        TTLS_PHASE2_EAP_MD5,
					        tmp_md5);
		       else
		         delete_config_eap_md5(&tmp_md5);
		       tmp_p2mschapv2 = NULL;
                     }
#line 3163 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1278 "config_grammar.y" /* yacc.c:1646  */
    {
                        set_current_leap(); /* define an empty leap struct*/
                      }
#line 3171 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1287 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("leap username: \"%s\"\n", (yyvsp[0].str));
		       set_current_leap();
		       if (!tmp_leap->username)
			 tmp_leap->username = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
                     }
#line 3184 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1295 "config_grammar.y" /* yacc.c:1646  */
    {
		       parameter_debug("leap password: \"%s\"\n", (yyvsp[0].str));
		       set_current_leap();
		       if (!tmp_leap->password)
			 tmp_leap->password = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
		     }
#line 3197 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1306 "config_grammar.y" /* yacc.c:1646  */
    {
                        set_current_mschapv2(); /* define an empty mschapv2 struct*/
                      }
#line 3205 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1315 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("mschapv2 username: \"%s\"\n", (yyvsp[0].str));
		       set_current_mschapv2();
		       if (!tmp_mschapv2->username)
			 tmp_mschapv2->username = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
                     }
#line 3218 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1323 "config_grammar.y" /* yacc.c:1646  */
    {
		       parameter_debug("mschapv2 password: \"%s\"\n", (yyvsp[0].str));
		       set_current_mschapv2();
		       if (!tmp_mschapv2->password)
			 tmp_mschapv2->password = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
		     }
#line 3231 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1334 "config_grammar.y" /* yacc.c:1646  */
    {
                        set_current_peap(); /* define an empty peap struct*/
                      }
#line 3239 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1343 "config_grammar.y" /* yacc.c:1646  */
    {
                            parameter_debug("ID: \"%s\"\n", (yyvsp[0].str));
			    set_current_peap();
			    if (!tmp_peap->identity)
			      tmp_peap->identity = (yyvsp[0].str);
			    else
			      free((yyvsp[0].str));
                          }
#line 3252 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1351 "config_grammar.y" /* yacc.c:1646  */
    {
                        parameter_debug("peap user cert: \"%s\"\n", (yyvsp[0].str));
			set_current_peap();
			if (!tmp_peap->user_cert)
			  tmp_peap->user_cert = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
                      }
#line 3265 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1359 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("peap user key: \"%s\"\n", (yyvsp[0].str));
			set_current_peap();
			if (!tmp_peap->user_key)
			  tmp_peap->user_key = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 3278 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1367 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("peap user pass: \"%s\"\n", (yyvsp[0].str));
			set_current_peap();
			if (!tmp_peap->user_key_pass)
			  tmp_peap->user_key_pass = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
        	      }
#line 3291 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1375 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("peap root_cert: \"%s\"\n", (yyvsp[0].str));
			set_current_peap();
			if (!tmp_peap->root_cert)
			  tmp_peap->root_cert = (yyvsp[0].str);
			else
			  free((yyvsp[0].str));
        	      }
#line 3304 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1383 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("peap root_dir: \"%s\"\n", (yyvsp[0].str));
			set_current_peap();
			if (!tmp_peap->root_dir)
			  tmp_peap->root_dir = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 3317 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1391 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("peap crl_dir: \"%s\"\n", (yyvsp[0].str));
			set_current_peap();
			if (!tmp_peap->crl_dir)
			  tmp_peap->crl_dir = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 3330 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1399 "config_grammar.y" /* yacc.c:1646  */
    {
		        parameter_debug("Session Resumption = YES\n");
		        set_current_peap();
		        if (tmp_peap->session_resume == RES_UNSET)
			  tmp_peap->session_resume = RES_YES;
		      }
#line 3341 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1405 "config_grammar.y" /* yacc.c:1646  */
    {
			parameter_debug("Session Resumption = NO\n");
			set_current_peap();
			if (tmp_peap->session_resume == RES_UNSET)
			  tmp_peap->session_resume = RES_NO;
		      }
#line 3352 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1411 "config_grammar.y" /* yacc.c:1646  */
    {
 		        parameter_debug("peap chunk: %d\n", (yyvsp[0].num));
			set_current_peap();
			if (tmp_peap->chunk_size == 0)
			  tmp_peap->chunk_size = (yyvsp[0].num);
  		      }
#line 3363 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1417 "config_grammar.y" /* yacc.c:1646  */
    {
		        parameter_debug("peap CN check : \"%s\"\n", (yyvsp[0].str));
                        set_current_peap();
                        if (!tmp_peap->cncheck)
                          tmp_peap->cncheck = (yyvsp[0].str);
                        else
                          free((yyvsp[0].str));
		      }
#line 3376 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1425 "config_grammar.y" /* yacc.c:1646  */
    {
  		        parameter_debug("match CN exactly : \"yes\"\n");
		        set_current_peap();
		        tmp_peap->cnexact = 1;
		    }
#line 3386 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1430 "config_grammar.y" /* yacc.c:1646  */
    {
  		        parameter_debug("match CN exactly : \"no\"\n");
		        set_current_peap();
		        tmp_peap->cnexact = 0;
       		    }
#line 3396 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1435 "config_grammar.y" /* yacc.c:1646  */
    {
	 	        parameter_debug("peap rand: \"%s\"\n", (yyvsp[0].str));
			set_current_peap();
			if (!tmp_peap->random_file)
			  tmp_peap->random_file = (yyvsp[0].str);
			else 
			  free((yyvsp[0].str));
        	      }
#line 3409 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1443 "config_grammar.y" /* yacc.c:1646  */
    {}
#line 3415 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1444 "config_grammar.y" /* yacc.c:1646  */
    {}
#line 3421 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1447 "config_grammar.y" /* yacc.c:1646  */
    {
                           parameter_debug("PEAP Allow Types: ALL\n");
			   set_current_peap();
			   SET_FLAG(tmp_peap->flags, CONFIG_PEAP_ALLOW_ALL);
                       }
#line 3431 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1459 "config_grammar.y" /* yacc.c:1646  */
    {
                          parameter_debug("PEAP Allow Type: MSCHAPV2\n");
	  	  	  set_current_peap();
			  SET_FLAG(tmp_peap->flags, CONFIG_PEAP_ALLOW_MSCV2);
                        }
#line 3441 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1464 "config_grammar.y" /* yacc.c:1646  */
    {
                          parameter_debug("PEAP Allow Type: MD5\n");
	  	  	  set_current_peap();
			  SET_FLAG(tmp_peap->flags, CONFIG_PEAP_ALLOW_MD5);
                        }
#line 3451 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1469 "config_grammar.y" /* yacc.c:1646  */
    {
                          parameter_debug("PEAP Allow Type: SIM\n");
	  	  	  set_current_peap();
			  SET_FLAG(tmp_peap->flags, CONFIG_PEAP_ALLOW_SIM);
                        }
#line 3461 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1474 "config_grammar.y" /* yacc.c:1646  */
    {
                          parameter_debug("PEAP Allow Type: OTP\n");
	  	  	  set_current_peap();
			  SET_FLAG(tmp_peap->flags, CONFIG_PEAP_ALLOW_OTP);
                        }
#line 3471 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1479 "config_grammar.y" /* yacc.c:1646  */
    {
                          parameter_debug("PEAP Allow Type: GTC\n");
	  	  	  set_current_peap();
			  SET_FLAG(tmp_peap->flags, CONFIG_PEAP_ALLOW_GTC);
                        }
#line 3481 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1487 "config_grammar.y" /* yacc.c:1646  */
    {
                             set_current_peap(); 
	   	             if (!config_eap_method_contains_method(tmp_peap->phase2,
								    EAP_TYPE_MSCHAPV2))
			       add_config_eap_method(&(tmp_peap->phase2),
						     EAP_TYPE_MSCHAPV2,
						     tmp_mschapv2);
			     else
			       delete_config_eap_mschapv2(&tmp_mschapv2);
			     tmp_mschapv2 = NULL;
                            }
#line 3497 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1498 "config_grammar.y" /* yacc.c:1646  */
    {
                             set_current_peap(); 
	   	             if (!config_eap_method_contains_method(tmp_peap->phase2,
								    EAP_TYPE_MD5))
			       add_config_eap_method(&(tmp_peap->phase2),
						     EAP_TYPE_MD5,
						     tmp_md5);
			     else
			       delete_config_eap_md5(&tmp_md5);
			     tmp_md5 = NULL;
                            }
#line 3513 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1509 "config_grammar.y" /* yacc.c:1646  */
    {
                             set_current_peap(); 
	   	             if (!config_eap_method_contains_method(tmp_peap->phase2,
								    EAP_TYPE_SIM))
			       add_config_eap_method(&(tmp_peap->phase2),
						     EAP_TYPE_SIM,
						     tmp_sim);
			     else
			       delete_config_eap_sim(&tmp_sim);
			     tmp_sim = NULL;
                            }
#line 3529 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1523 "config_grammar.y" /* yacc.c:1646  */
    {
                        set_current_sim(); /* define an empty sim struct*/
                      }
#line 3537 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1532 "config_grammar.y" /* yacc.c:1646  */
    {
                       parameter_debug("sim username: \"%s\"\n", (yyvsp[0].str));
		       set_current_sim();
		       if (!tmp_sim->username)
			 tmp_sim->username = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
                     }
#line 3550 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1540 "config_grammar.y" /* yacc.c:1646  */
    {
		       parameter_debug("sim password: \"%s\"\n", (yyvsp[0].str));
		       set_current_sim();
		       if (!tmp_sim->password)
			 tmp_sim->password = (yyvsp[0].str);
		       else
			 free((yyvsp[0].str));
		     }
#line 3563 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1548 "config_grammar.y" /* yacc.c:1646  */
    {
  		       parameter_debug("sim auto_realm: \"yes\"\n");
		       set_current_sim();
		       tmp_sim->auto_realm = 1;
		   }
#line 3573 "config_grammar.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1553 "config_grammar.y" /* yacc.c:1646  */
    {
  		       parameter_debug("sim auto_realm: \"no\"\n");
		       set_current_sim();
		       tmp_sim->auto_realm = 0;
		   }
#line 3583 "config_grammar.c" /* yacc.c:1646  */
    break;


#line 3587 "config_grammar.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1559 "config_grammar.y" /* yacc.c:1906  */

