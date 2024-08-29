cmake_minimum_required(VERSION 3.0)
project(robot)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SRC src/*.cpp)

add_executable(robot ${SRC} main.cpp)

set(TEST_NAME test_app)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.2.0
)

FetchContent_MakeAvailable(Catch2)

if (TEST_SAMPLES_FILE)
    add_definitions(-DTEST_SAMPLES_FILE="${CMAKE_SOURCE_DIR}/${TEST_SAMPLES_FILE}")
    message(STATUS "Test file path set to ${CMAKE_SOURCE_DIR}/${TEST_SAMPLES_FILE}")
else ()
    add_definitions(-DTEST_SAMPLES_FILE="${CMAKE_SOURCE_DIR}/test_cases.txt")
    message(STATUS "Test file path not set. Defaulting to ${CMAKE_SOURCE_DIR}/test_cases.txt")
endif ()



add_executable(position_test src/Position.cpp test-cases/test_position.cpp)
target_link_libraries(position_test PRIVATE Catch2::Catch2WithMain)
