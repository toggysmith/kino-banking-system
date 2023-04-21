#include "terminal/user_interface.hpp"

using Terminal::UserInterface;

void
sign_in_user()
{
  const std::string_view& selectedOption = UserInterface::show_options(
    { "Sign in as customer", "Sign in as administrator" });
}

int
main()
{
  UserInterface::show_heading("Welcome to Kino Banking.");

  sign_in_user();

  return 0;
}
