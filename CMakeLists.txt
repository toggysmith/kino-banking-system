cmake_minimum_required(VERSION 3.24)
project(kino)

set(CMAKE_CXX_STANDARD 17)

add_executable(kino src/main.cpp src/core/user_privilege_level.hpp src/core/access_manager.hpp src/terminal/user_interface.hpp src/terminal/user_interface.cpp src/core/account.cpp src/core/currency.hpp src/core/money.hpp src/core/money.cpp src/core/exchange_rate_manager.hpp src/core/exchange_rate_manager.cpp src/core/branches.hpp src/util/name.hpp src/util/name.cpp src/core/customer.hpp src/core/customer.cpp src/util/date.hpp src/util/date.cpp)
