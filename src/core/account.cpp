#include "account.hpp"

namespace Core {

Account::Account(Money balance)
  : account_number(Account::total_no_of_accounts++)
  , balance(balance)
{
}

void
Account::deposit(const int64_t amount)
{
  balance.add(amount);
}

void
Account::withdraw(const int64_t amount)
{
  balance.subtract(amount);
}

int64_t
  Account::get_account_number() const
{
  return account_number;
}

Money
Account::get_balance() const
{
  return balance;
}

int64_t Account::total_no_of_accounts = 0;

}