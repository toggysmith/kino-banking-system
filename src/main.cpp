// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include <GLFW/glfw3.h>
#include <gtest/gtest.h>
#include <imgui.h>

#include "core/window_manager.hpp"

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

    window_manager.render([]() {
      bool is_open{ true };
      ImGui::Begin("Another Window", &is_open);
      ImGui::Text("Hello from another window!");
      ImGui::End();
    });
  }

  return EXIT_SUCCESS;
}