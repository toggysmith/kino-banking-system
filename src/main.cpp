#include "core/account.hpp"
#include "core/currency.hpp"
#include "core/exchange_rate_manager.hpp"
#include "core/money.hpp"
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
  using Core::Account;
  using Core::Currency;
  using Core::Money;

  Account account{Money{Currency::usd, 50}};

  account.deposit(32);

  std::cout << account.get_balance().get_value() << std::endl;

  account.withdraw(17);

  std::cout << account.get_balance().get_value() << std::endl;

  std::cout << account.get_account_number() << std::endl;

  Account account2{Money{Currency::gbp, 2523}};

  std::cout << account2.get_account_number() << std::endl;

  return 0;
}
