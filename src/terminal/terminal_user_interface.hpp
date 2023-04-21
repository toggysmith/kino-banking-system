#ifndef KINO_TERMINAL_USER_INTERFACE_HPP
#define KINO_TERMINAL_USER_INTERFACE_HPP

#include <iostream>
#include <string>
#include <string_view>

struct TerminalUserInterface
{
  static void show_heading(std::string_view);
};

#endif