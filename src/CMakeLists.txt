cmake_minimum_required(VERSION 3.0)

add_subdirectory(ssr-libev)

set(ssr-prefix ${CMAKE_CURRENT_SOURCE_DIR}/../shadowsocksr-libev)
set(prefix ${ssr-prefix}/src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${prefix})
include_directories(${libev_include_dirs})
include_directories(${libcork_include_dirs})
include_directories(${libipset_include_dirs})
include_directories(${libudns_include_dirs})
include_directories(${libsodium_include_dirs})

set (ss_lib_net
        ${ss_lib_common}
        ${LIBCRYPTO}
        libipset
        ${PCRE_LIBRARIES}
        udns
        sodium
        )

add_executable(ssr-local
        ssr_local.c
        )

target_link_libraries(ssr-local
        ${ss_lib_net}
        )