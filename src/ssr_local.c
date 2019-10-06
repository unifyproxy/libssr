#include "ssr_local.h"



void
main(int argc, char* argv[]) {
    int option_index = 0;

    char* server;
    char* port;
    char* lport;
    char* passwd;
    char* pid;
    char* timeout;
    char* method;
    // ssr
    char* protocol;
    char* protocol_arg;
    char* obfs;
    char* obfs_arg;

    for(;;) {
        int c = getopt_long(argc, argv, "s:p:l:P:I:t:m:z:Z:x:X:", ssr_option, &option_index);
        if(c == -1){
            break;
        }

        switch (c) {
            case 's':
                // s for server
                server = optarg;
                break;
            case 'p':
                // p for server port
                port = optarg;
                break;
            case 'l':
                // l for local port
                lport = optarg;
                break;
            case 'P':
                // P for Password
                passwd = optarg;
                break;
            case 'I':
                // I for pId
                pid = optarg;
                break;
            case 't':
                // t for timeout
                timeout = optarg;
                break;
            case 'm':
                // m for method
                method = optarg;
                break;
            // SSR part
            case 'z':
                // z for protocol
                protocol = optarg;
                break;
            case 'Z':
                // Z for protocol_arg
                protocol_arg = optarg;
                break;
            case 'x':
                // x for obfs
                obfs = optarg;
                break;
            case 'X':
                // X for obfs_arg
                obfs_arg = optarg;
                break;
            default:
                printf("wrong arguments.");
        }

        option_index = 0;
    }
}