// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "customer_menu.hpp"

#include "main_menu.hpp"

namespace Menus {

void
CustomerMenu::render(std::unique_ptr<Menu>& current_menu) const
{
  ImGui::Begin(
    "Kino Banking System / Customer Menu", nullptr, main_window_flags);

  if (ImGui::Button("Back")) {
    current_menu = std::make_unique<MainMenu>();
  }

  ImGui::End();
}

}