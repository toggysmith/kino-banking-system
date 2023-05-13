// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "main_menu.hpp"

#include <iostream>
#include <memory>

#include "customer_menu.hpp"

namespace Menus {

MainMenu::MainMenu()
  : Menu("Main")
{
}

void
MainMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  ImGui::Text("What kind of user are you?");

  if (ImGui::Button("Customer")) {
    menu_stack.push_front(std::make_unique<CustomerMenu>());
    std::cout << menu_stack.size() << std::endl;
  } else if (ImGui::Button("Manager")) {
    std::cout << "Manager\n";
  } else if (ImGui::Button("Admin")) {
    std::cout << "Admin\n";
  }
}

}