#include "user_interface.hpp"

namespace Terminal {

void
UserInterface::show_heading(const std::string_view heading)
{
  std::cout << std::string(100, '#') << '\n';
  std::cout << "# " << heading << '\n';
  std::cout << std::string(100, '#') << '\n';
  std::cout << '\n';
}

std::string_view
UserInterface::show_options(const std::vector<const std::string_view>& options)
{
  for (auto i = 0; i < options.size(); i++) {
    const std::string_view& option = options[i];

    std::cout << (i + 1) << ". " << option << '\n';
  }

  std::cout << '\n';

  std::cout << "Select an option: ";
  size_t selectedOptionNumber =
    get_integer_in_range_from_user(1, options.size());
  std::cout << '\n';

  return options[selectedOptionNumber - 1];
}

int
UserInterface::get_integer_in_range_from_user(const int lower_bound_of_range,
                                              const int upper_bound_of_range)
{
  int user_input;
  bool was_user_input_invalid{ true };

  do {
    std::cin >> user_input;

    if (std::cin.good()) {
      bool is_user_input_in_range = user_input >= lower_bound_of_range &&
                                    user_input <= upper_bound_of_range;

      if (is_user_input_in_range) {
        was_user_input_invalid = false;
      }
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (was_user_input_invalid) {
      std::cout << "Invalid input detected. Try again: ";
    }
  } while (was_user_input_invalid);

  return user_input;
}

UserInterface::UserInterface() {}

}