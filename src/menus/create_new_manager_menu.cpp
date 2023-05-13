// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "create_new_manager_menu.hpp"

#include <imgui.h>

#include "../core/database_manager.hpp"

#include <iostream>
namespace Menus {

CreateNewManagerMenu::CreateNewManagerMenu()
  : Menu("Create New Manager")
  , name("")
  , password("")
  , confirm_password("")
{
}

void
CreateNewManagerMenu::render(
  std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  Menu::render(menu_stack);

  ImGui::InputText("Name", const_cast<char*>(name), IM_ARRAYSIZE(name));

  ImGui::InputText("Password",
                   const_cast<char*>(password),
                   IM_ARRAYSIZE(password),
                   ImGuiInputTextFlags_Password);

  ImGui::InputText("Confirm Password",
                   const_cast<char*>(confirm_password),
                   IM_ARRAYSIZE(confirm_password),
                   ImGuiInputTextFlags_Password);

  Core::DatabaseManager* database_manager =
    Core::DatabaseManager::get_instance();

  if (ImGui::Button("Submit")) {
    std::string sql = "INSERT INTO manager VALUES('" + std::string(name) +
                      "', '" + std::string(password) + "');";

    database_manager->run_sql(sql.c_str());
  }
}

}