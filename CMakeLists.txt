cmake_minimum_required(VERSION 3.0)
project(libssr)

set(ssr_prefix ./shadowsocksr-libev)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/shadowsocksr-libev/cmake)

set(with_crypto_library "openssl" CACHE STRING "build with the given crypto library, TYPE=openssl|polarssl|mbedtls default=openssl")


include ( dist )
include ( configure )

configure_file(${ssr_prefix}/config.h.cmake ${CMAKE_BINARY_DIR}/shadowsocksr-libev/config.h)
include_directories(${CMAKE_BINARY_DIR}/shadowsocksr-libev)

add_subdirectory(${ssr_prefix}/libsodium)
add_subdirectory(${ssr_prefix}/libcork)
add_subdirectory(${ssr_prefix}/libipset)
add_subdirectory(${ssr_prefix}/libev)


add_subdirectory(${ssr_prefix}/libudns)

add_subdirectory(src)

