// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_MENUS_MAIN_MENU_HPP
#define KINO_MENUS_MAIN_MENU_HPP

#include <deque>
#include <memory>

#include "menu.hpp"

namespace Menus {

class MainMenu : public Menu
{
public:
  explicit MainMenu();
  void render(std::deque<std::unique_ptr<Menu>>&) const override;
};

}

#endif