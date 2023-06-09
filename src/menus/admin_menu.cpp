// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "admin_menu.hpp"

#include <imgui.h>

#include "admin/create_manager_menu.hpp"
#include "admin/view_managers_menu.hpp"

namespace Menus {

AdminMenu::AdminMenu()
  : Menu("Admin")
{
}

void
AdminMenu::render(std::deque<std::unique_ptr<Menu>>& menu_stack) const
{
  Menu::render(menu_stack);

  if (ImGui::Button("Create new manager account")) {
    menu_stack.push_front(std::make_unique<Admin::CreateManagerMenu>());
  }

  if (ImGui::Button("View managers")) {
    menu_stack.push_front(std::make_unique<Admin::ViewManagersMenu>());
  }
}

}