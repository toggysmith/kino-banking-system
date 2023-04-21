cmake_minimum_required(VERSION 3.24)
project(kino)

set(CMAKE_CXX_STANDARD 17)

add_executable(kino src/main.cpp src/core/user_mode.hpp src/core/access_manager.hpp src/core/access_manager.cpp)
