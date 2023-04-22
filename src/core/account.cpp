#include "account.hpp"

namespace Core {

Account::Account(Money balance)
  : balance(balance)
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

Money
Account::get_balance() const
{
  return balance;
}

}