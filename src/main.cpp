#include <iostream>

#include "core/access_manager.hpp"
#include "terminal/terminal_user_interface.hpp"

int
main()
{
  AccessManager access_manager{ UserPrivilegeLevel::customer };

  TerminalUserInterface::show_heading("Hello, world!");

  const std::string_view& selectedOption = TerminalUserInterface::show_options(
    { "Create account", "Delete account", "Change account details" });

  std::cout << selectedOption << '\n';

  return 0;
}
