// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "menu.hpp"

#include <imgui.h>

#include <functional>

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

struct Menu::TableActionButton
{
  const std::string name;
  const std::function<void(table_row_t&)> callback;
};

void
Menu::show_table(const table_column_names_t& column_names,
                 const table_data_t& data,
                 const table_action_buttons_t& action_buttons)
{
  auto flags =
    ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersV | ImGuiTableFlags_ScrollY;

  ImGui::BeginTable("table",
                    static_cast<int>(column_names.size()),
                    flags,
                    ImGui::GetContentRegionAvail());

  for (const auto& column_name : column_names) {
    ImGui::TableSetupColumn(column_name.c_str());
  }

  if (!action_buttons.empty()) {
    ImGui::TableSetupColumn("Actions");
  }

  ImGui::TableHeadersRow();

  for (const auto& row : data) {
    ImGui::TableNextRow();

    for (int i = 0; i < row.size(); i++) {
      const auto& col = row[i];

      ImGui::TableSetColumnIndex(i);
      if (col) {
        ImGui::Text("%s", (*col).c_str());
      } else {
        ImGui::Text("NULL");
      }
    }
  }

  ImGui::EndTable();
}

void
Menu::show_table(const table_column_names_t& column_names,
                 const table_data_t& data)
{
  show_table(column_names, data, {});
}

}