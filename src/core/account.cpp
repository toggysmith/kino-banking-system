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
Account::get_branch_number() const
{
  return branch_number;
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

Name
Account::get_name() const
{
  return name;
}

int64_t Account::total_no_of_accounts = 0;

}