// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "update_manager_menu.hpp"

#include <iostream> // REMOVE

namespace Menus::Admin {

UpdateManagerMenu::UpdateManagerMenu(int row_id)
  : Menu("Update Manager")
{
  std::cout << "row id is " << row_id << std::endl; // REMOVE
}

void
UpdateManagerMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  Menu::render(menu_stack);
}

}