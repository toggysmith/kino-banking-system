// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "main_menu.hpp"

#include <memory>

#include <imgui.h>

#include "admin_menu.hpp"
#include "customer_menu.hpp"
#include "manager_menu.hpp"

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
  } else if (ImGui::Button("Manager")) {
    menu_stack.push_front(std::make_unique<ManagerMenu>());
  } else if (ImGui::Button("Admin")) {
    menu_stack.push_front(std::make_unique<AdminMenu>());
  }
}

}