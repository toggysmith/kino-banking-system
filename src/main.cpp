#include "core/account.hpp"
#include "core/branches.hpp"
#include "core/currency.hpp"
#include "core/exchange_rate_manager.hpp"
#include "core/money.hpp"
#include "core/name.hpp"
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
  return 0;
}
