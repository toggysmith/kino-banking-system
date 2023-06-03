// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include <deque>
#include <memory>

#include <GLFW/glfw3.h>
#include <gtest/gtest.h>
#include <imgui.h>

#include "core/window_manager.hpp"
#include "menus/main_menu.hpp"
#include "menus/menu.hpp"

std::deque<std::unique_ptr<Menus::Menu>> menu_stack;

void
render()
{
  const auto io = ImGui::GetIO();

  ImGui::SetNextWindowSize(
    ImVec2(io.DisplaySize.x - 50, io.DisplaySize.y - 50));
  ImGui::SetNextWindowPos(ImVec2(25, 25));

  std::unique_ptr<Menus::Menu>& current_state = menu_stack[0];

  std::string path = "Kino Banking System";

  if (menu_stack.size() > 1) {
    path += " - ";
  }

  for (int i = menu_stack.size() - 2; i >= 0; i--) {
    path += menu_stack[i]->name;

    if (i != 0) {
      path += " / ";
    }
  }

  const ImGuiWindowFlags main_window_flags = ImGuiWindowFlags_NoResize |
                                             ImGuiWindowFlags_NoCollapse |
                                             ImGuiWindowFlags_NoMove;

  ImGui::Begin(path.c_str(), nullptr, main_window_flags);

  if (current_state != nullptr) {
    current_state->render(menu_stack);
  }

  ImGui::End();
}

int
main()
{
  Core::WindowManager window_manager;

  menu_stack.push_back(std::make_unique<Menus::MainMenu>());

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