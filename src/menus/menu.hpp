// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_MENUS_MENU_HPP
#define KINO_MENUS_MENU_HPP

#include <deque>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

namespace Menus {

class Menu
{
public:
  explicit Menu(std::string_view name);
  virtual ~Menu() = default;

  virtual void render(std::deque<std::unique_ptr<Menu>>&) const;

  const std::string name;

protected:
  static void show_table(
    const std::vector<std::string>&,
    const std::vector<std::vector<std::optional<std::string>>>&);
};

}

#endif