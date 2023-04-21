#include <iostream>

#include "core/access_manager.hpp"

int
main()
{
  AccessManager access_manager{};

  access_manager.userPrivilegeLevel = UserPrivilegeLevel::customer;

  return 0;
}
