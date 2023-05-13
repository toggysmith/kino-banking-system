// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "admin_menu.hpp"

namespace Menus {

AdminMenu::AdminMenu()
  : Menu("Admin")
{
}

void
AdminMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  if (ImGui::Button("Back")) {
    menu_stack.pop_front();
  }
}

}