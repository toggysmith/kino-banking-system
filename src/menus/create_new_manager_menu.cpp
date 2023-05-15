// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "create_new_manager_menu.hpp"

#include <imgui.h>

#include <vector>

#include "../core/database_manager.hpp"

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

  std::vector<const char*> error_messages;

  bool does_name_exist = !std::string(name).empty();
  bool does_password_exist = !std::string(password).empty();
  bool does_confirm_password_exist = !std::string(confirm_password).empty();
  bool does_confirm_password_match_password =
    std::string(password) == std::string(confirm_password);

  if (!does_name_exist) {
    error_messages.push_back("Name must be specified.");
  }

  if (!does_password_exist) {
    error_messages.push_back("Password must be specified.");
  }

  if (!does_confirm_password_exist) {
    error_messages.push_back("Confirm password must be specified.");
  }

  if (!does_confirm_password_match_password && does_password_exist &&
      does_confirm_password_exist) {
    error_messages.push_back("Passwords don't match.");
  }

  ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0, 0.0, 0.0, 1.0));
  for (const auto& error_message : error_messages) {
    ImGui::BulletText("%s", error_message);
  }
  ImGui::PopStyleColor();

  if (error_messages.empty()) {
    if (ImGui::Button("Create")) {
      std::string sql = "INSERT INTO manager VALUES('" + std::string(name) +
                        "', '" + std::string(password) + "');";

      database_manager->run_sql(sql.c_str());

      menu_stack.pop_front();
    }
  }
}

}