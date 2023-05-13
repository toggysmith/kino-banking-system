// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include <memory>

#include <GLFW/glfw3.h>
#include <gtest/gtest.h>
#include <imgui.h>
#include <sqlite3.h>

#include "core/window_manager.hpp"
#include "menus/main_menu.hpp"
#include "menus/menu.hpp"

void
render()
{
  static std::unique_ptr<Menus::Menu> current_menu{ new Menus::MainMenu{} };

  const auto io = ImGui::GetIO();

  ImGui::SetNextWindowSize(
    ImVec2(io.DisplaySize.x - 50, io.DisplaySize.y - 50));
  ImGui::SetNextWindowPos(ImVec2(25, 25));

  current_menu->render(current_menu);
}

int
main()
{
  Core::WindowManager window_manager{};

  std::optional<GLFWwindow*> window_optional{ window_manager.get_window() };

  if (!window_optional) {
    return EXIT_FAILURE;
  }

  GLFWwindow* window = *window_optional;

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    window_manager.start_frame();

    render();

    window_manager.finish_frame();
  }

  return EXIT_SUCCESS;
}