// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_MENU_HPP
#define KINO_MENU_HPP

#include <deque>
#include <memory>
#include <string>
#include <string_view>

#include <imgui.h>

namespace Menus {

class Menu
{
public:
  explicit Menu(std::string_view name);
  virtual ~Menu() = default;

  virtual void render(std::deque<std::unique_ptr<Menu>>&) const = 0;

  const std::string name;
};

}

#endif