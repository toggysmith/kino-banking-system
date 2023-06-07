// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_MENUS_ADMIN_UPDATE_MANAGER_FIELD_MENU_HPP
#define KINO_MENUS_ADMIN_UPDATE_MANAGER_FIELD_MENU_HPP

#include "../menu.hpp"

#include <string_view>

namespace Menus::Admin {

class UpdateManagerFieldMenu : public Menu
{
public:
  explicit UpdateManagerFieldMenu(int, std::string_view);
  void render(std::deque<std::unique_ptr<Menu>>&) const override;

private:
  const int row_id;
  const std::string_view column_name;
};

}

#endif