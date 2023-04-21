#include <iostream>

#include "core/access_manager.hpp"

int
main()
{
  access_manager accessManager{};

  accessManager.setCurrentUserMode(UserMode::customer);

  const UserMode userMode = accessManager.getCurrentUserMode();

  if (userMode == UserMode::customer) {
    std::cout << "Customer!!!\n";
  }

  return 0;
}
