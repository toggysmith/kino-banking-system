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
# GLFW
############################################################################################################################################
find_package(OpenGL REQUIRED)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
        GIT_TAG 3.3.8
)
FetchContent_MakeAvailable(glfw)

############################################################################################################################################
# ImGui
############################################################################################################################################
set(IMGUI_PATH ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui)
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library(ImGui STATIC ${IMGUI_SOURCES})

set(IMGUI_BACKENDS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends)
add_library(ImGuiBackends STATIC ${IMGUI_BACKENDS_PATH}/imgui_impl_glfw.cpp ${IMGUI_BACKENDS_PATH}/imgui_impl_opengl3.cpp)
target_include_directories(ImGuiBackends PUBLIC ${IMGUI_PATH})
target_link_libraries(ImGuiBackends glfw)

############################################################################################################################################
# SQLite 3
############################################################################################################################################
find_package(SQLite3)

############################################################################################################################################
# Main executable
############################################################################################################################################
add_executable(kino src/main.cpp src/core/window_manager.hpp src/core/window_manager.cpp src/menus/menu.hpp src/menus/main_menu.hpp src/menus/main_menu.cpp src/menus/customer_menu.hpp src/menus/customer_menu.cpp src/menus/menu.cpp src/menus/manager_menu.hpp src/menus/manager_menu.cpp src/menus/admin_menu.cpp)
target_link_libraries(
        kino
        GTest::gtest_main
        glfw
        ${OPENGL_gl_LIBRARY}
        ImGui
        ImGuiBackends
        ${SQLite3_LIBRARIES}
)
target_include_directories(kino PUBLIC ${IMGUI_PATH} ${IMGUI_BACKENDS_PATH} ${SQLite3_INCLUDE_DIRS})

############################################################################################################################################
# Test runner executable
############################################################################################################################################
add_executable(test_runner tests/test_something.cpp src/core/window_manager.hpp src/core/window_manager.cpp src/menus/menu.hpp src/menus/main_menu.hpp src/menus/main_menu.cpp src/menus/customer_menu.hpp src/menus/customer_menu.cpp src/menus/menu.cpp src/menus/manager_menu.hpp src/menus/manager_menu.cpp src/menus/admin_menu.cpp)
target_link_libraries(
        test_runner
        GTest::gtest_main
        glfw
        ${OPENGL_gl_LIBRARY}
        ImGui
        ImGuiBackends
        ${SQLite3_LIBRARIES}
)
target_include_directories(test_runner PUBLIC ${IMGUI_PATH} ${IMGUI_BACKENDS_PATH} ${SQLite3_INCLUDE_DIRS})
gtest_discover_tests(test_runner)