// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "menu.hpp"

#include <imgui.h>

namespace Menus {

Menu::Menu(std::string_view name)
  : name(name)
{
}

void
Menu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.7f, 0.3f, 0.4f, 0.8f });
  if (ImGui::Button("Go back")) {
    menu_stack.pop_front();
  }
  ImGui::PopStyleColor();
}

}