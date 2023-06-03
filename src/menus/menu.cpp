// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "menu.hpp"

#include <imgui.h>

#include <functional>
#include <iostream>

namespace Menus {

Menu::Menu(std::string_view name)
  : name(name)
{
}

void
Menu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.7f, 0.3f, 0.4f, 0.8f });
  if (ImGui::Button("Go back")) {
    menu_stack.pop_front();
  }
  ImGui::PopStyleColor();
}

void
Menu::show_table(const Core::DatabaseManager::ColumnNames& column_names,
                 Core::DatabaseManager::TableData& data,
                 const TableActionButtons& action_buttons)
{
  auto flags =
    ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersV | ImGuiTableFlags_ScrollY;

  ImGui::BeginTable(
    "table",
    static_cast<int>(column_names.size() + action_buttons.size() - 1),
    flags,
    ImGui::GetContentRegionAvail());

  for (const auto& column_name : column_names) {
    if (column_name != "rowid") {
      ImGui::TableSetupColumn(column_name.c_str());
    }
  }

  if (!action_buttons.empty()) {
    ImGui::TableSetupColumn("Actions");
  }

  ImGui::TableHeadersRow();

  for (auto& row : data) {
    const int row_id{ std::stoi(*row[0]) };
    ImGui::PushID(row_id);

    ImGui::TableNextRow();

    for (int i = 1; i < row.size(); i++) {
      const auto& col = row[i];

      ImGui::TableSetColumnIndex(i - 1);
      if (col) {
        ImGui::Text("%s", (*col).c_str());
      } else {
        ImGui::Text("NULL");
      }
    }

    ImGui::TableSetColumnIndex(row.size() - 1);
    for (int i = 0; i < action_buttons.size(); i++) {
      // Make the buttons run horizontally rather than stack vertically.
      bool is_first_button{ i == 0 };
      if (!is_first_button) {
        ImGui::SameLine();
      }

      if (ImGui::Button(action_buttons[i].name.c_str())) {
        action_buttons[i].callback(std::stoi(*row[0]));
      }
    }

    ImGui::PopID();
  }

  ImGui::EndTable();
}

void
Menu::show_table(const Core::DatabaseManager::ColumnNames& column_names,
                 Core::DatabaseManager::TableData& data)
{
  show_table(column_names, data, {});
}

}