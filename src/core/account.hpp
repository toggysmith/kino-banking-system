#ifndef KINO_ACCOUNT_HPP
#define KINO_ACCOUNT_HPP

#include <cstdlib>

#include "currency.hpp"
#include "money.hpp"
#include "name.hpp"

namespace Core {

class Account
{
public:
  explicit Account(Name, int64_t, Money);

  void deposit(int64_t);
  void withdraw(int64_t);
  [[nodiscard]] int64_t get_branch_number() const;
  [[nodiscard]] int64_t get_account_number() const;
  [[nodiscard]] Money get_balance() const;
  [[nodiscard]] Name get_name() const;

private:
  static int64_t total_no_of_accounts;
  const int64_t account_number;
  const int64_t branch_number;
  Money balance;
  const Name name;
};

}
#endif
