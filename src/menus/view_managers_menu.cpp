// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "view_managers_menu.hpp"

namespace Menus {

ViewManagersMenu::ViewManagersMenu()
  : Menu("View Managers")
{
}

void
ViewManagersMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  Menu::render(menu_stack);
}

}