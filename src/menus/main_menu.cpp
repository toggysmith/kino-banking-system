// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "main_menu.hpp"

#include <iostream>
#include <memory>

#include "customer_menu.hpp"

namespace Menus {

void
MainMenu::render(std::unique_ptr<Menu>& current_menu) const
{
  ImGui::Begin("Kino Banking System", nullptr, main_window_flags);

  ImGui::Text("What kind of user are you?");

  if (ImGui::Button("Customer")) {
    current_menu = std::make_unique<CustomerMenu>();
  } else if (ImGui::Button("Manager")) {
    std::cout << "Manager\n";
  } else if (ImGui::Button("Admin")) {
    std::cout << "Admin\n";
  }

  ImGui::End();
}

}