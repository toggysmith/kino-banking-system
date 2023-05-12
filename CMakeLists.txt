# SPDX-License-Identifier: CC-BY-NC-4.0
# Author: Toggy Smith (toggysmith@gmail.com)

############################################################################################################################################
# CMake setup
############################################################################################################################################
cmake_minimum_required(VERSION 3.24)
project(kino)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)

############################################################################################################################################
# GoogleTest
############################################################################################################################################
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows: Prevent overriding the parent project's compiler/linker settings
enable_testing()
include(GoogleTest)

############################################################################################################################################
# Main executable
############################################################################################################################################
add_executable(kino src/main.cpp)
target_link_libraries(
        kino
        GTest::gtest_main
)

############################################################################################################################################
# Test runner executable
############################################################################################################################################
add_executable(test_runner tests/test_something.cpp)
target_link_libraries(
        test_runner
        GTest::gtest_main
)
gtest_discover_tests(test_runner)