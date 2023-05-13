// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_MENU_HPP
#define KINO_MENU_HPP

#include <imgui.h>
#include <memory>
#include <string>

namespace Menus {

class Menu
{
public:
  virtual ~Menu() = default;

  virtual void render(std::unique_ptr<Menu>&) const = 0;

protected:
  const static ImGuiWindowFlags main_window_flags =
    ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoMove;
};

}

#endif