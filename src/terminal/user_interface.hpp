#ifndef KINO_USER_INTERFACE_HPP
#define KINO_USER_INTERFACE_HPP

#include <iostream>
#include <string>
#include <string_view>

namespace Terminal {

class UserInterface
{
public:
  static void show_heading(std::string_view);
  [[nodiscard]] static std::string_view show_options(
    const std::vector<const std::string_view>&);

private:
  UserInterface();

  [[nodiscard]] static int get_integer_in_range_from_user(int, int);
};

}

#endif