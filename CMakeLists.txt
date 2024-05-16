cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

set(PROJECT_NAME basealttask)

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

# target_link_libraries(${PROJECT_NAME} PRIVATE /usr/lib64/libjsoncpp.so)


target_compile_options(${PROJECT_NAME} PRIVATE -std=c++20)