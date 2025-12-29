cmake_minimum_required(VERSION 3.10)
project(renderer)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/source/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(raylib REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
