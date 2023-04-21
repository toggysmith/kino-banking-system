#include "terminal_user_interface.hpp"

void
TerminalUserInterface::show_heading(const std::string_view heading)
{
  std::cout << std::string(100, '#') << '\n';
  std::cout << "# " << heading << '\n';
  std::cout << std::string(100, '#') << '\n';
}