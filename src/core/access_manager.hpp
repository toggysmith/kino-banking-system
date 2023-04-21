#ifndef KINO_ACCESS_MANAGER_HPP
#define KINO_ACCESS_MANAGER_HPP

#include "user_privilege_level.hpp"

namespace Core {

struct AccessManager
{
  UserPrivilegeLevel userPrivilegeLevel;
};

}

#endif