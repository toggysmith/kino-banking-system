// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "customer_menu.hpp"

namespace Menus {

CustomerMenu::CustomerMenu()
  : Menu("Customer")
{
}

void
CustomerMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  Menu::render(menu_stack);
}

}