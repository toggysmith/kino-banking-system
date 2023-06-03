// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "update_manager_menu.hpp"

#include "imgui.h"

#include "../../core/database_manager.hpp"
#include <iostream>
#include <utility>

namespace Menus::Admin {

UpdateManagerMenu::UpdateManagerMenu(std::string table_name, const int row_id)
  : Menu("Update Manager")
  , table_name(std::move(table_name))
  , row_id(row_id)
{
}

void
UpdateManagerMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  Menu::render(menu_stack);

  // "Go back" button might have been pressed, so we need to check.
  if (menu_stack[0]->name != name)
    return;

  // Get the row from the database.
  Core::DatabaseManager* database_manager =
    Core::DatabaseManager::get_instance();

  std::string query{ "SELECT * FROM " + table_name +
                     " WHERE rowid = " + std::to_string(row_id) };

  const auto results{ database_manager->run_sql(query.c_str()) };

  // Display the row.
  if (results) {
    auto [column_names, table_data] = *results;

    show_table(column_names, table_data);
  } else {
    ImGui::Text("This record does not exist.");
  }
}

}