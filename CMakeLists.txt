cmake_minimum_required(VERSION 3.5...4.3)

project(robot)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SRC src/*.cpp)

add_executable(robot ${SRC} main.cpp)

# Enable testing for the project
enable_testing()
add_subdirectory(test-cases)