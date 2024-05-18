cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_NAME basealttask)

set(EXECUTABLE_OUTPUT_PATH usr/bin)
set(ARCHIVE_OUTPUT_DIRECTORY usr/bin)
set(LIBRARY_OUTPUT_NAME usr/bin)
set(RUNTIME_OUTPUT_NAME usr/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

project(${PROJECT_NAME})

find_package(nlohmann_json REQUIRED)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/package.cpp
)

include_directories(/usr/include)

target_include_directories(${PROJECT_NAME} PRIVATE /usr/include)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE /usr/lib64/libbasealttask.so)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

target_compile_options(${PROJECT_NAME} PRIVATE -std=c++14)