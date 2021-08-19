##############################################
# Standard CMake Policy
##############################################
cmake_minimum_required(VERSION 3.14)
if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif(POLICY CMP0048)

include(CMakeDependentOption)
#include(GUNInstallDirs)

##############################################
# Project
##############################################
project(asio LANGUAGES C CXX)  

set(SRC_ROOT          ${CMAKE_CURRENT_LIST_DIR})

##############################################
# Version Information
##############################################
set(_VERSION_MAJOR 0)
set(_VERSION_MINOR 1)
set(_VERSION_PATCH 0)
set(_VERSION_STRING "${_VERSION_MAJOR}.${_VERSION_MINOR}.${_VERSION_PATCH}")

message(STATUS "${PROJECT_NAME} Version: ${_VERSION_STRING}")


##############################################
# Compiler Flags
##############################################
set(CXX_FLAGS
    -g                        # 保存调试信息
    -Wall                     # 编译后显示所有的警告
    -m64                      # 64位程序
    -Wextra                   # 打印额外的警告错误
    #-Werror                   # 警告变错误
    -Wno-unused-parameter     # 忽略未使用变量的警告
    -Wno-strict-aliasing      # 忽略严格别名规则的警告
    -O2                       # 开启优化 O2
    -std=c++11                # c++11
    -lpthread                 # pthread
)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

# CMAKE_BUILD_TYPE配置构建类型，默认为空，可以选择Debug 或者 Release
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(BOOST_VERSION 1.62.0)

find_package(Boost ${BOOST_VERSION} EXACT REQUIRED COMPONENTS date_time filesystem system)

# 同步测试asio timer
add_executable(asio_timer_test asio_timer_test.cpp)

target_link_libraries(asio_timer_test 
PUBLIC
Boost::date_time 
Boost::system 
)

# 异步测试asio timer
add_executable(asio_async_timer_test asio_async_timer_test.cpp)

target_link_libraries(asio_async_timer_test 
PUBLIC
Boost::date_time 
Boost::system 
)

# 异步测试asio timer  使用lambda
add_executable(asio_timer_lambda asio_timer_lambda_test.cpp)

target_link_libraries(asio_timer_lambda 
PUBLIC
Boost::date_time 
Boost::system 
)

# asio_tcp_use_test
add_executable(asio_tcp_use asio_tcp_use_test.cpp)

target_link_libraries(asio_tcp_use
PUBLIC
Boost::date_time 
Boost::system 
)

# asio_timer_server
add_executable( asio_timer_server  asio_timer_server_test.cpp)

target_link_libraries( asio_timer_server
PUBLIC
Boost::date_time 
Boost::system 
)

# asio_async_time_bind_test
add_executable( asio_async_time_bind  asio_async_time_bind_test.cpp)

target_link_libraries( asio_async_time_bind
PUBLIC
Boost::date_time 
Boost::system 
)

# asio_async_echo_client
add_executable( asio_async_echo_client  asio_async_echo_client.cpp)

target_link_libraries( asio_async_echo_client
PUBLIC
Boost::date_time 
Boost::system 
)


# asio_async_echo_server
add_executable( asio_async_echo_server asio_async_echo_server.cpp)

target_link_libraries( asio_async_echo_server
PUBLIC
Boost::date_time 
Boost::system 
)
