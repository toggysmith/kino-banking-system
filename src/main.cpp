#include "terminal/user_interface.hpp"

enum class Service
{
  customer_portal,
  atm,
  admin_portal
};

Service
ask_user_to_select_service()
{
  using Terminal::UserInterface;

  const std::string_view& selection =
    UserInterface::show_options({ "Customer portal", "ATM", "Admin portal" });

  if (selection == "Customer portal") {
    return Service::customer_portal;
  } else if (selection == "ATM") {
    return Service::atm;
  } else if (selection == "Admin portal") {
    return Service::admin_portal;
  }
}

int
main()
{
  Service selected_service{ ask_user_to_select_service() };

  return 0;
}