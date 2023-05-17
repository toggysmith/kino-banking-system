// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "menu.hpp"

#include <imgui.h>

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
Menu::show_table(
  const std::vector<std::string>& column_names,
  const std::vector<std::vector<std::optional<std::string>>>& data)
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

}