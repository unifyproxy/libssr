#include <shadowsocks.h>
#include "ssr_local.h"


void
usage() {
    printf("-----------------------------------------------------------------------\n");
    printf("----Usage: ssr-local                                               ----\n");
    printf("----    (--server|-s) server host or ip address                    ----\n");
    printf("----    (--port|-p)  port of SSR on server                         ----\n");
    printf("----    (--lport|-l) local port                                    ----\n");
    printf("----    (--passwd|-P)  password                                    ----\n");
    printf("----    (--timeout|-t) connection timeout <Optional>               ----\n");
    printf("----    (--method|-m)  encrypt method     <Optional>               ----\n");
    printf("----    (--protocol|-z)     SSR Protocol                           ----\n");
    printf("----    (--protocol_arg|-Z) SSR Protocol argument                  ----\n");
    printf("----    (--obfs|-x)     SSR OBFS type                              ----\n");
    printf("----    (--obfs_arg|-X) SSR OBFS arg                               ----\n");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
//    printf("----                                                               ----");
    printf("-----------------------------------------------------------------------\n");
}

void signal_cb(EV_P_ ev_signal *w, int revents) {
    if(revents & EV_SIGNAL) {
        switch (w->signum)
        {
        case SIGINT:
        case SIGTERM:
        ev_unloop(EV_A_ EVUNLOOP_ALL);
            break;
        
        default:
            break;
        }
    }
}


void start_ssr_server(ssr_server_t* profile) {
    struct ev_loop* loop = EV_DEFAULT;

    listen_ctx_t listen_ctx;
    ssr_server_t* p = profile;

    server_def_t* serv = &listen_ctx.servers[0];

    // init encd
    enc_init(&serv->cipher, p->password, p->method);

    // init obfs
    init_obfs(serv, ss_strdup(p->protocol), ss_strdup(p->protocol_arg), ss_strdup(p->obfs), ss_strdup(p->obfs_arg));

    cork_dllist_init(&serv->connections);

    // ev setup

    ev_signal sigint_watcher;
    ev_signal sigterm_watcher;
    ev_signal_init(&sigint_watcher, signal_cb, SIGINT);
    ev_signal_init(&sigterm_watcher, signal_cb, SIGTERM);

    ev_run(loop, 0);


}


int
main(int argc, char *argv[]) {
    int option_index = 0;

    char *server;
    char *port;
    char *lport;
    char *passwd;
    char *timeout;
    char *method;
    // ssr
    char *protocol;
    char *protocol_arg;
    char *obfs;
    char *obfs_arg;

    for (;;) {
        int c = getopt_long(argc, argv, "s:p:l:P:t:m:z:Z:x:X:", ssr_option, &option_index);
        if (c == -1) {
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


    if (server == 0 ||
        port == 0 ||
        lport == 0 ||
        passwd == 0 ||
        protocol == 0 ||
        protocol_arg == 0 ||
        obfs == 0 ||
        obfs_arg == 0
            ) {
        usage();
        return 1;
    }

    profile_t *profile = ss_malloc(sizeof(profile_t));
    profile->remote_host = server;
    profile->remote_port = port;
    profile->local_addr = "127.0.0.1";
    profile->local_port = lport;
    profile;

    start_ss_local_server()
    start_ss_local_server();
}
