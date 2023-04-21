#ifndef KINO_ACCESS_MANAGER_HPP
#define KINO_ACCESS_MANAGER_HPP

#include "user_mode.hpp"

class access_manager
{
public:
  [[nodiscard]] UserMode getCurrentUserMode() const;
  void setCurrentUserMode(UserMode);

private:
  UserMode currentUserMode;
};

#endif