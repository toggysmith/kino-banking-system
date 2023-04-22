#ifndef KINO_ACCOUNT_HPP
#define KINO_ACCOUNT_HPP

#include <cstdlib>

#include "currency.hpp"
#include "money.hpp"

namespace Core {

class Account
{
public:
  explicit Account(Money);

  void deposit(int64_t);
  void withdraw(int64_t);
  [[nodiscard]] Money get_balance() const;

private:
  Money balance;
};

}
#endif
