#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "core/customer.hpp"
#include "terminal/user_interface.hpp"
#include "util/date.hpp"

using Core::Customer;
using Terminal::UserInterface;
using Util::Date;

std::vector<Customer> customers;

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
  UserInterface::show_heading("Admin Portal / Create Customer");

  std::string forename;
  std::string middle_names;
  std::string last_name;
  int date_of_birth_day;
  int date_of_birth_month;
  int date_of_birth_year;
  int64_t branch_number;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Enter the forename of the customer: ";
  std::getline(std::cin, forename);
  std::cout << "Enter the middle name(s) of the customer: ";
  std::getline(std::cin, middle_names);
  std::cout << "Enter the last name of the customer: ";
  std::getline(std::cin, last_name);
  std::cout << "Enter the day the customer was born: ";
  std::cin >> date_of_birth_day;
  std::cout << "Enter the month the customer was born: ";
  std::cin >> date_of_birth_month;
  std::cout << "Enter the year the customer was born: ";
  std::cin >> date_of_birth_year;
  std::cout << "Enter the branch number of the customer: ";
  std::cin >> branch_number;

  const Name name{ forename, middle_names, last_name };

  const Date date_of_birth{ date_of_birth_day,
                            date_of_birth_month,
                            date_of_birth_year };

  const Customer customer{ name, date_of_birth, branch_number };

  customers.push_back(customer);

  std::cout
    << "\nCustomer created successfully. Press any character to proceed.";
  std::cin.ignore();
  std::cin.get();
  std::cout << '\n';
}

void
show_view_customers_menu()
{
  UserInterface::show_heading("Admin Portal / View Customers");

  std::cout << std::left << std::setw(40) << "Name" << std::setw(20)
            << "Date of Birth" << std::setw(20) << "Branch Number" << std::endl;

  for (const auto& customer : customers) {
    std::cout << std::left << std::setw(40) << customer.get_name()
              << std::setw(20) << customer.get_date_of_birth() << std::setw(20)
              << customer.get_branch_number() << '\n';
  }

  std::cout << '\n';
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
  bool finished{ false };

  while (!finished) {
    UserInterface::show_heading("Admin Portal");

    std::vector<const std::string_view> options = { "Create customer",
                                                    "View customers",
                                                    "Update customer records",
                                                    "Delete customer",
                                                    "Exit" };

    const std::string_view& selection{ UserInterface::show_options(options) };

    if (selection == options[0]) {
      show_create_customer_menu();
    } else if (selection == options[1]) {
      show_view_customers_menu();
    } else if (selection == options[2]) {
      show_update_customer_records_menu();
    } else if (selection == options[3]) {
      show_delete_customer_menu();
    } else if (selection == options[4]) {
      finished = true;
    }
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