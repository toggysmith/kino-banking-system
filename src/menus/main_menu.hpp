// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include <memory>

#include "menu.hpp"

namespace Menus {

class MainMenu : public Menu
{
public:
  void render(std::unique_ptr<Menu>&) const override;
};

}