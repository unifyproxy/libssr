cmake_minimum_required(VERSION 3.0)

set(ssr-prefix ${CMAKE_CURRENT_SOURCE_DIR}/../../shadowsocksr-libev)
set(prefix ${ssr-prefix}/src)

set(SOURCE_FILES_SNI
        ${prefix}/http.c
        ${prefix}/tls.c
        ${prefix}/rule.c)

set(SOURCE_FILES_LOCAL
        ${prefix}/utils.c
        ${prefix}/jconf.c
        ${prefix}/json.c
        ${prefix}/encrypt.c
        ${prefix}/udprelay.c
        ${prefix}/cache.c
        ${prefix}/acl.c
        ${prefix}/netutils.c
        ${prefix}/local.c
        ${SOURCE_FILES_SNI})

set(SOURCE_FILES_TUNNEL
        ${prefix}/utils.c
        ${prefix}/jconf.c
        ${prefix}/json.c
        ${prefix}/encrypt.c
        ${prefix}/udprelay.c
        ${prefix}/cache.c
        ${prefix}/netutils.c
        ${prefix}/tunnel.c)

set(SOURCE_FILES_SERVER
        ${prefix}/utils.c
        ${prefix}/jconf.c
        ${prefix}/json.c
        ${prefix}/encrypt.c
        ${prefix}/udprelay.c
        ${prefix}/cache.c
        ${prefix}/acl.c
        ${prefix}/resolv.c
        ${prefix}/netutils.c
        ${prefix}/server.c
        ${SOURCE_FILES_SNI})

set(SOURCE_FILES_MANAGER
        ${prefix}/utils.c
        ${prefix}/jconf.c
        ${prefix}/json.c
        ${prefix}/manager.c)

set(SOURCE_FILES_REDIR
        ${prefix}/utils.c
        ${prefix}/jconf.c
        ${prefix}/json.c
        ${prefix}/encrypt.c
        ${prefix}/netutils.c
        ${prefix}/cache.c
        ${prefix}/udprelay.c
        ${prefix}/redir.c
        ${SOURCE_FILES_SNI})

include_directories(${prefix})
include_directories(${libev_include_dirs})
include_directories(${libcork_include_dirs})
include_directories(${libipset_include_dirs})
include_directories(${libudns_include_dirs})
include_directories(${libsodium_include_dirs})


if (WIN32)
    list ( APPEND SOURCE_FILES_LOCAL win32.c )
    list ( APPEND SOURCE_FILES_TUNNEL win32.c )
    list ( APPEND SOURCE_FILES_SERVER win32.c )
endif ()

#add_executable(ss_local ${SOURCE_FILES_LOCAL})
#add_executable(ss_tunnel ${SOURCE_FILES_TUNNEL})
#add_executable(ss_server ${SOURCE_FILES_SERVER})
#add_executable(ss_manager ${SOURCE_FILES_MANAGER})
#add_executable(ss_redir ${SOURCE_FILES_REDIR})
#add_library(libshadowsocks-libev ${SOURCE_FILES_LOCAL})

#set_target_properties(ss_local PROPERTIES
#        COMPILE_DEFINITIONS MODULE_LOCAL
#        )
#set_target_properties(ss_tunnel PROPERTIES
#        COMPILE_DEFINITIONS MODULE_TUNNEL
#        )
#set_target_properties(ss_server PROPERTIES
#        COMPILE_DEFINITIONS MODULE_REMOTE
#        )
#set_target_properties(ss_manager PROPERTIES
#        COMPILE_DEFINITIONS MODULE_MANAGER
#        )
#set_target_properties(ss_redir PROPERTIES
#        COMPILE_DEFINITIONS MODULE_REDIR
#        )
#target_compile_definitions(libshadowsocks-libev
#        PRIVATE MODULE_LOCAL LIB_ONLY
#        )
#set_target_properties(libshadowsocks-libev PROPERTIES SUFFIX ".la")

set (ss_lib_common
        ev
        m
        libcork)

set (ss_lib_net
        ${ss_lib_common}
        ${LIBCRYPTO}
        libipset
        ${PCRE_LIBRARIES}
        udns
        sodium
        )

if (WIN32)
    list ( APPEND ss_lib_net Ws2_32 )
endif()

#target_link_libraries(ss_local
#        ${ss_lib_net}
#        )
#target_link_libraries(ss_tunnel
#        ${ss_lib_net}
#        )
#target_link_libraries(ss_server
#        ${ss_lib_net}
#        )
#target_link_libraries(ss_manager
#        ${ss_lib_common}
#        )
#target_link_libraries(ss_redir
#        ${ss_lib_net}
#        )