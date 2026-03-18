cmake_minimum_required(VERSION 3.10)
project(SentinelGuardSDK VERSION 1.0.0)

# C++ Standard set kora (Modern C++ dorkar security-r jonno)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories (Header files kothay ache seta bole deya)
include_directories(include)

# Library-r shob source files eksathe kora
file(GLOB SOURCES "src/*.cpp")

# Static library toiri kora (Jeta manufacturers-ra tader hardware-e integrate korbe)
add_library(SentinelGuard STATIC ${SOURCES})

# Example/Demo executable toiri kora
add_executable(SentinelDemo examples/Hardware_Integration_Demo.cpp)

# Example-er sathe library-tike link kora
target_link_libraries(SentinelDemo SentinelGuard)

message(STATUS "SentinelGuard SDK: Ready for cross-platform build.")
