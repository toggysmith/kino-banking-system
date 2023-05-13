// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "manager_menu.hpp"

namespace Menus {

ManagerMenu::ManagerMenu()
  : Menu("Manager")
{
}

void
ManagerMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  if (ImGui::Button("Back")) {
    menu_stack.pop_front();
  }
}

}