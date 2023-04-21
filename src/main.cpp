#include <iostream>

#include "core/access_manager.hpp"
#include "terminal/terminal_user_interface.hpp"

int
main()
{
  AccessManager access_manager{ UserPrivilegeLevel::customer };

  TerminalUserInterface::show_heading("Hello, world!");

  return 0;
}
