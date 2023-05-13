// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "customer_menu.hpp"

#include "main_menu.hpp"

namespace Menus {

CustomerMenu::CustomerMenu()
  : Menu("Customer")
{
}

void
CustomerMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  if (ImGui::Button("Back")) {
    menu_stack.pop_front();
  }
}

}