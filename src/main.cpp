#include "terminal/user_interface.hpp"

using Terminal::UserInterface;

enum class Service
{
  customer_portal,
  atm,
  admin_portal
};

Service
ask_user_to_select_service()
{
  UserInterface::show_heading("Services");

  std::vector<const std::string_view> options = { "Customer portal",
                                                  "ATM",
                                                  "Admin portal" };

  const std::string_view& selection{ UserInterface::show_options(options) };

  if (selection == options[0]) {
    return Service::customer_portal;
  } else if (selection == options[1]) {
    return Service::atm;
  } else if (selection == options[2]) {
    return Service::admin_portal;
  }
}

void
show_create_customer_menu()
{
}

void
show_view_customers_menu()
{
}

void
show_update_customer_records_menu()
{
}

void
show_delete_customer_menu()
{
}

void
run_admin_portal_service()
{
  UserInterface::show_heading("Admin Portal");

  std::vector<const std::string_view> options = { "Create customer",
                                                  "View customers",
                                                  "Update customer records",
                                                  "Delete customer" };

  const std::string_view& selection{ UserInterface::show_options(options) };

  if (selection == options[0]) {
    show_create_customer_menu();
  } else if (selection == options[1]) {
    show_view_customers_menu();
  } else if (selection == options[2]) {
    show_update_customer_records_menu();
  } else if (selection == options[3]) {
    show_delete_customer_menu();
  }
}

int
main()
{
  Service selected_service{ ask_user_to_select_service() };

  switch (selected_service) {
    case Service::admin_portal:
      run_admin_portal_service();
      break;
  }

  return 0;
}