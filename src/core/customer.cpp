#include "customer.hpp"

namespace Core {

Customer::Customer(const Name name,
                   const Date date_of_birth,
                   const int64_t branch_number)

  : name(name)
  , date_of_birth(date_of_birth)
  , branch_number(branch_number)
{
}

void
Customer::add_account(const Account& account)
{
  accounts.push_back(account);
}

const std::vector<Account>&
Customer::get_accounts() const
{
  return accounts;
}

}