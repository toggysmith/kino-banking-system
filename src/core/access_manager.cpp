#include "access_manager.hpp"

UserMode
access_manager::getCurrentUserMode() const
{
  return currentUserMode;
}

void
access_manager::setCurrentUserMode(const UserMode newUserMode)
{
  currentUserMode = newUserMode;
}