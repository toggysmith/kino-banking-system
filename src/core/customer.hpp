#ifndef KINO_CUSTOMER_HPP
#define KINO_CUSTOMER_HPP

#include <cstdlib>
#include <vector>

#include "../util/date.hpp"
#include "../util/name.hpp"
#include "account.hpp"

using Util::Date;

namespace Core {

class Customer
{
public:
  explicit Customer(Name, Date, int64_t);

  void add_account(const Account&);
  [[nodiscard]] const std::vector<Account>& get_accounts() const;

  [[nodiscard]] int64_t get_id() const;
  [[nodiscard]] const Name& get_name() const;
  [[nodiscard]] const Date& get_date_of_birth() const;
  [[nodiscard]] int64_t get_branch_number() const;

private:
  static int64_t id_counter;
  const int64_t id;
  const Name name;
  const Date date_of_birth;
  std::vector<Account> accounts;
  const int64_t branch_number;
};

}

#endif