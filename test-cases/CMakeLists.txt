cmake_minimum_required(VERSION 3.0)

project(robottest)

SET(CMAKE_CXX_STANDARD 17)

set(TEST_NAME test_app)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.2.0
)

FetchContent_MakeAvailable(Catch2)

MESSAGE(STATUS "Current directory is ${CMAKE_SOURCE_DIR}")

add_executable(test_position ../src/Position.cpp test_position.cpp)
target_link_libraries(test_position PRIVATE Catch2::Catch2WithMain)

add_test(test_position test_position)