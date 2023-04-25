#include "name.hpp"

namespace Util {

Name::Name(const std::string_view forename,
           const std::string_view middle_name,
           const std::string_view last_name)
  : forename(forename)
  , middle_name(middle_name)
  , last_name(last_name)
{
}

const std::string&
Name::get_forename() const
{
  return forename;
}

std::pair<const bool, const std::string&>
Name::get_middle_name() const
{
  if (middle_name.empty()) {
    return { false, middle_name };
  } else {
    return { true, middle_name };
  }
}

std::pair<const bool, const std::string&>
Name::get_last_name() const
{
  return (last_name.empty())
           ? (std::pair<const bool, const std::string&>{ false, last_name })
           : (std::pair<const bool, const std::string&>{ true, last_name });
}

std::ostream&
operator<<(std::ostream& out, const Name& name)
{
  std::string final_string = name.get_forename();

  {
    const auto [success, middle_name] = name.get_middle_name();

    if (success) {
      final_string += " " + middle_name;
    }
  }

  {
    const auto [success, last_name] = name.get_last_name();

    if (success) {
      final_string += " " + last_name;
    }
  }

  return out << final_string;
}

}