#include "account.hpp"

#include <utility>

namespace Core {

Account::Account(Name name, int64_t branch_number, Money balance)
  : name(std::move(name))
  , branch_number(branch_number)
  , account_number(Account::total_no_of_accounts++)
  , balance(balance)
{
}

bool
Account::deposit(const Money& amount)
{
  if (amount.get_currency() == balance.get_currency()) {
    balance.add(amount.get_value());
    return true;
  } else {
    const auto [success, exchanged_amount] =
      amount.convert_currency_to(balance.get_currency());

    if (success) {
      balance.add(exchanged_amount.get_value());
      return true;
    } else {
      return false;
    }
  }
}

bool
Account::withdraw(const Money& amount)
{
  if (amount.get_currency() == balance.get_currency()) {
    balance.subtract(amount.get_value());
    return true;
  } else {
    const auto [success, exchanged_amount] =
      amount.convert_currency_to(balance.get_currency());

    if (success) {
      balance.subtract(exchanged_amount.get_value());
      return true;
    } else {
      return false;
    }
  }
}

int64_t
Account::get_branch_number() const
{
  return branch_number;
}

int64_t
Account::get_account_number() const
{
  return account_number;
}

const Money&
Account::get_balance() const
{
  return balance;
}

Name
Account::get_name() const
{
  return name;
}

bool
Account::transfer_to(Account& account, const Money& amount)
{
  bool was_withdrawal_successful = withdraw(amount);
  bool was_deposit_successful = account.deposit(amount);

  // INFO: Both of the Boolean values above should be the same because the only
  // way withdrawal or depositing can fail is if there isn't a known exchange
  // rate between two currencies.
  assert(was_withdrawal_successful == was_deposit_successful);

  bool was_transfer_successful =
    was_withdrawal_successful && was_deposit_successful;
  return was_transfer_successful;
}

int64_t Account::total_no_of_accounts = 0;

}