// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "view_managers_menu.hpp"

#include <imgui.h>

#include "../core/database_manager.hpp"

#include <iostream>

namespace Menus {

ViewManagersMenu::ViewManagersMenu()
  : Menu("View Managers")
{
}

void
ViewManagersMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  Menu::render(menu_stack);

  // Get a list of managers
  Core::DatabaseManager* database_manager =
    Core::DatabaseManager::get_instance();

  const auto results =
    database_manager->run_sql("SELECT rowid, * FROM manager");

  // If there are no results, show a message indicating this
  if (!results) {
    ImGui::Text("There are no results.");
    return;
  }
  // If there are results, show them
  else {
    auto [column_names, table_data] = *results;

    // Create a callback for deleting rows.
    const auto delete_callback = [](int row_id) {
      Core::DatabaseManager* database_manager =
        Core::DatabaseManager::get_instance();

      const std::string query{ "DELETE FROM manager WHERE rowid = " +
                               std::to_string(row_id) };

      database_manager->run_sql(query.c_str());
    };

    TableActionButton action_button{ "Delete", delete_callback };

    show_table(column_names, table_data, { action_button });
  }
}

}