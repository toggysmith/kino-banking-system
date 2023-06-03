// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_MENUS_ADMIN_UPDATE_MANAGER_MENU_HPP
#define KINO_MENUS_ADMIN_UPDATE_MANAGER_MENU_HPP

#include <deque>
#include <memory>
#include <string>

#include "../menu.hpp"

namespace Menus::Admin {

class UpdateManagerMenu : public Menu
{
public:
  explicit UpdateManagerMenu(std::string, int);
  void render(std::deque<std::unique_ptr<Menu>>&) const override;

private:
  const std::string table_name;
  const int row_id;
};

}

#endif