#ifndef _SSR_LOCAL_H
#define _SSR_LOCAL_H

#define LIB_ONLY

#include <config.h>
#include <common.h>
#include <local.h>
#include <encrypt.h>
#include <shadowsocks.h>
#include <utils.h>

#include <getopt.h>


struct option ssr_option[] = {
        {"server",       required_argument, 0, 's'},
        {"port",         required_argument, 0, 'p'},
        {"lport",        required_argument, 0, 'l'},
        {"passwd",       required_argument, 0, 'P'},
        {"timeout",      required_argument, 0, 't'},
        {"method",       required_argument, 0, 'm'},

        // SSR OPS
        {"protocol",     required_argument, 0, 'z'},
        {"protocol_arg", required_argument, 0, 'Z'},
        {"obfs",         required_argument, 0, 'x'},
        {"obfs_arg",     required_argument, 0, 'X'},
};

enum METHOD_e {
    M_TABLE,
    M_RC4,
    M_RC4_MD5,

    // AES Family
            M_AES_128_CFB,
    M_AES_192_CFB,
    M_AES_256_CFB,
    M_AES_128_CTR,
    M_AES_192_CTR,
    M_AES_256_CTR,

    M_BF_CFB,

    // CAMELLIA Family
            M_CAMELLIA_128_CFB,
    M_CAMELLIA_192_CFB,
    M_CAMELLIA_256_CFB,


    M_SALSA20,
    M_XSALSA20,
    M_chacha20,
    M_xchacha20,
    M_chacha20_ietf,
};

const char **METHOD_STR = {
        "table", "rc4", "rc4-md5",
        "aes-128-cfb", "aes-192-cfb", "aes-256-cfb",
        "aes-128-ctr", "aes-192-ctr", "aes-256-ctr",
        "bf-cfb", "camellia-128-cfb", "camellia-192-cfb",
        "camellia-256-cfb", "cast5-cfb", "des-cfb",
        "idea-cfb", "rc2-cfb", "seed-cfb", "salsa20",
        "chacha20", "chacha20-ietf"
};

const char **METHOD_STR2 =
        {
                "none",
                "table",
                "rc4",
                "rc4-md5-6",
                "rc4-md5",
                "aes-128-cfb",
                "aes-192-cfb",
                "aes-256-cfb",
                "aes-128-ctr",
                "aes-192-ctr",
                "aes-256-ctr",
                "bf-cfb",
                "camellia-128-cfb",
                "camellia-192-cfb",
                "camellia-256-cfb",
                "cast5-cfb",
                "des-cfb",
                "idea-cfb",
                "rc2-cfb",
                "seed-cfb",
                "salsa20",
                "chacha20",
                "chacha20-ietf"
        };

enum PROTOCOL_e {
    P_ORIGIN,
    P_VERIFY_DEFLATE,
    P_AUTH_SHA1_V4,
    P_AUTH_SHA128_MD5,
    P_AUTH_SHA128_SHA1,

    // auth chain *
            P_AUTH_CHAIN_A,
    P_AUTH_CHAIN_B,
    P_AUTH_CHAIN_C,
    P_AUTH_CHAIN_D,
    P_AUTH_CHAIN_E,
    P_AUTH_CHAIN_F,
};

enum OBFS_e {
    O_PLAIN,
    O_HTTP_SIMPLE,
    O_HTTP_POST,
    O_TLS12_TICKET_AUTH,
    O_TLS12_TICKET_FASTAUTH
};


typedef struct {
    char* server;
    int server_port;
    char* password;
    char* method;

    char* protocol;
    char* protocol_arg;
    char* obfs;
    char* obfs_arg;

    char* local;
    int local_port;
} ssr_server_t;


#endif // _SSR_LOCAL_H
