#include "customer.hpp"

#include <utility>

namespace Core {

Customer::Customer(Name name,
                   const Date date_of_birth,
                   const int64_t branch_number)

  : id(id_counter++)
  , name(std::move(name))
  , date_of_birth(date_of_birth)
  , branch_number(branch_number)
{
}

void
Customer::add_account(const Account& account)
{
  accounts.push_back(account);
}

int
Customer::get_id() const
{
  return id;
}

const std::vector<Account>&
Customer::get_accounts() const
{
  return accounts;
}

const Name&
Customer::get_name() const
{
  return name;
}

const Date&
Customer::get_date_of_birth() const
{
  return date_of_birth;
}

int64_t
Customer::get_branch_number() const
{
  return branch_number;
}

int Customer::id_counter{ 0 };

}