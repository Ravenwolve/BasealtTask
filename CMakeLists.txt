cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

SET (PROJECT_NAME ALTRepo)

project(${PROJECT_NAME})

list(APPEND CMAKE_FIND_LIBRARY_SUFFIXES ".so.4")

find_package (CURL REQUIRED)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/get.cpp
)

include_directories(${CURL_INCLUDE_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE includes)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES})

target_compile_options(${PROJECT_NAME} PRIVATE -std=c++20)