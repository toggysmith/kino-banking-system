// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_VIEW_MANAGERS_MENU_HPP
#define KINO_VIEW_MANAGERS_MENU_HPP

#include <deque>
#include <memory>

#include "menu.hpp"

namespace Menus {

class ViewManagersMenu : public Menu
{
public:
  explicit ViewManagersMenu();
  void render(std::deque<std::unique_ptr<Menu>>&) const override;
};

}

#endif