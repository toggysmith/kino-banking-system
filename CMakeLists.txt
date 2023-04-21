cmake_minimum_required(VERSION 3.24)
project(kino)

set(CMAKE_CXX_STANDARD 17)

add_executable(kino src/main.cpp src/core/user_privilege_level.hpp src/core/access_manager.hpp src/terminal/terminal_user_interface.hpp src/terminal/terminal_user_interface.cpp)
