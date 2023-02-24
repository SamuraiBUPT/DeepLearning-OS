cmake_minimum_required(VERSION 3.23)
project(Deep_Learning_OS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
        src/hello.cpp
        src/main.cpp)

add_executable(Deep_Learning_OS ${SOURCES})

target_include_directories(Deep_Learning_OS
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include)
