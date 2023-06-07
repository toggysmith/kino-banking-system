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

  // Define some useful variables:
  const bool is_row_id_in_table{ std::find(std::begin(column_names),
                                           std::end(column_names),
                                           "rowid") != std::end(column_names) };
  const int number_of_needed_columns{ [&]() {
    int number_of_columns_needed{ 0 };

    number_of_columns_needed += static_cast<int>(column_names.size());

    if (!action_buttons.empty()) {
      number_of_columns_needed++;
    }

    if (is_row_id_in_table) {
      number_of_columns_needed--;
    }

    return number_of_columns_needed;
  }() };

  // Something is wrong if there are action buttons but no row id provided.
  assert(is_row_id_in_table || action_buttons.empty());

  ImGui::BeginTable(
    "table", number_of_needed_columns, flags, ImGui::GetContentRegionAvail());

  for (const auto& column_name : column_names) {
    if (column_name != "rowid") {
      ImGui::TableSetupColumn(column_name.c_str());
    }
  }

  if (!action_buttons.empty()) {
    ImGui::TableSetupColumn("Actions");
  }

  ImGui::TableHeadersRow();

  int imgui_id{0};

  for (auto& row : data) {
    const int row_id{ is_row_id_in_table ? std::stoi(*row[0]) : 0 };

    ImGui::PushID(imgui_id++);

    ImGui::TableNextRow();

    for (int i = (is_row_id_in_table ? 1 : 0); i < row.size(); i++) {
      const auto& col = row[i];

      ImGui::TableSetColumnIndex(i - (is_row_id_in_table ? 1 : 0));
      if (col) {
        ImGui::Text("%s", (*col).c_str());
      } else {
        ImGui::Text("NULL");
      }
    }

    // Show action buttons if there are any.
    if (!action_buttons.empty()) {
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