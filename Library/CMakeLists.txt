cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_NAME basealttask)


set(LIBRARY_OUTPUT_PATH usr/lib64)
file(COPY include/get.hpp DESTINATION usr/include/${PROJECT_NAME})

project(${PROJECT_NAME})

list(APPEND CMAKE_FIND_LIBRARY_SUFFIXES ".so.4")

find_package(CURL REQUIRED)


add_library(
    ${PROJECT_NAME} SHARED
    src/get.cpp
)

include_directories(${CURL_INCLUDE_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES})

target_compile_options(${PROJECT_NAME} PRIVATE -std=c++14)