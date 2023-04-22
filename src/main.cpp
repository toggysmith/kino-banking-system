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
  using Core::Account;
  using Core::Currency;
  using Core::Money;
  using Core::Name;

  Account toggy_account{ Name{ "Tony", "Oliver Gabriel", "Smith" },
                         1,
                         Money{ Currency::cad, 50 } };
  Account rebecca_account{ Name{ "Rebecca", "", "" },
                           1,
                           Money{ Currency::eur, 25 } };

  std::cout << toggy_account.get_balance().get_value() << std::endl;
  std::cout << rebecca_account.get_balance().get_value() << std::endl
            << std::endl;

  toggy_account.transfer_to(rebecca_account, Money{ Currency::sgd, 10 });

  std::cout << toggy_account.get_balance().get_value() << std::endl;
  std::cout << rebecca_account.get_balance().get_value() << std::endl
            << std::endl;

  return 0;
}
