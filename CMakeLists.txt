﻿# Copyright 2021 SMS
# License(Apache-2.0)

# 指定最小版本号
cmake_minimum_required(VERSION 3.16)

# 指定项目名和版本号
project(Math
    VERSION     0.0.0
    DESCRIPTION "A simple linear algebra header-only library."
    HOMEPAGE_URL "https://github.com/ShenMian/Math"
    LANGUAGES    CXX C)

# 指定默认编译类型
if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 选项
option(BUILD_TESTS "Build tests" ON)

# 输出基本信息
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.22.0")
    cmake_host_system_information(RESULT OS_PRETTY_NAME QUERY DISTRIB_PRETTY_NAME)
endif()
message(STATUS "OS")
message(STATUS "|- Name   : ${CMAKE_SYSTEM_NAME}(${OS_PRETTY_NAME})")
message(STATUS "`- Version: ${CMAKE_SYSTEM_VERSION}")
message(STATUS "Compiler")
message(STATUS "|- ID     : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "`- Version: ${CMAKE_CXX_COMPILER_VERSION}")

# 指定构建目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin")

# 指定 Win32 下要定义的宏
if(WIN32)
    list(APPEND MATH_DEFINES _CRT_SECURE_NO_WARNINGS _SCL_SECURE_NO_WARNINGS UNICODE _UNICODE NOMINMAX)
endif()

# 静态链接 MSVC 运行库
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

if(UNIX)
    add_link_options("-ldl")
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory("tests")
endif()
