// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "view_managers_menu.hpp"

#include <imgui.h>

#include "../core/database_manager.hpp"

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

  const auto results = database_manager->run_sql("SELECT * FROM manager");

  if (results) {
    for (const auto& row : *results) {
      std::string row_string;

      for (const auto& column : row) {
        if (column) {
          row_string += *column + " ";
        } else {
          row_string += "NULL ";
        }
      }

      ImGui::Text("%s", row_string.c_str());
    }
  } else {
    ImGui::Text("There are no results.");
  }
}

}