// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include <deque>
#include <memory>

#include "menu.hpp"

namespace Menus {

class CustomerMenu : public Menu
{
public:
  explicit CustomerMenu();
  void render(std::deque<std::unique_ptr<Menu>>&) const override;
};

}