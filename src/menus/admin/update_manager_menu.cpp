// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "update_manager_menu.hpp"

#include "imgui.h"

#include <memory>
#include <utility>
// REMOVE:
#include <iostream>

#include "update_manager_field_menu.hpp"

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

    Core::DatabaseManager::ColumnNames new_column_names{ "rowid",
                                                         "Field",
                                                         "Value" };
    Core::DatabaseManager::TableData new_table_data;

    for (size_t i = 0; i < table_data[0].size(); i++) {
      const auto column_value{ table_data[0][i] };
      const auto column_name{ column_names[i] };

      new_table_data.push_back({ std::to_string(i),
                                 column_name,
                                 column_value ? *column_value : "NULL" });
    }

    // Create a callback for the edit button.
    const auto edit_callback = [&menu_stack, &new_table_data](int row_id) {
      menu_stack.push_front(std::make_unique<UpdateManagerFieldMenu>(
        row_id, *new_table_data[row_id][1]));
    };

    show_table(new_column_names, new_table_data, { { "Edit", edit_callback } });
  } else {
    ImGui::Text("This record does not exist.");
  }
}

}