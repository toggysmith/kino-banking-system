// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "update_manager_field_menu.hpp"

namespace Menus::Admin {

UpdateManagerFieldMenu::UpdateManagerFieldMenu(
  const int row_id,
  const std::string_view column_name)
  : Menu("Update Field")
  , row_id(row_id)
  , column_name(column_name)
{
}

void
UpdateManagerFieldMenu::render(
  std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  Menu::render(menu_stack);
}

}