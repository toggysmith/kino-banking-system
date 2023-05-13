// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_CREATE_NEW_MANAGER_MENU_HPP
#define KINO_CREATE_NEW_MANAGER_MENU_HPP

#include <deque>
#include <memory>
#include <string>

#include "menu.hpp"

namespace Menus {

class CreateNewManagerMenu : public Menu
{
public:
  explicit CreateNewManagerMenu();
  void render(std::deque<std::unique_ptr<Menu>>&) const override;

private:
  const char name[100];
  const char password[100];
  const char confirm_password[100];
};

}

#endif