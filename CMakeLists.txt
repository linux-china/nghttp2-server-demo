cmake_minimum_required(VERSION 3.12)
project(nghttp_server)

set(CMAKE_CXX_STANDARD 11)

set(OPENSSL_ROOT_DIR /usr/local/Cellar/openssl/1.0.2p)
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

find_package(Boost REQUIRED)


add_executable(nghttp_server main.cpp)
target_link_libraries(nghttp_server ssl crypto boost_system nghttp2 nghttp2_asio)
