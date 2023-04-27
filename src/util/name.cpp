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

std::optional<std::string>
Name::get_middle_name() const
{
  if (middle_name.empty()) {
    return std::nullopt;
  } else {
    return middle_name;
  }
}

std::optional<std::string>
Name::get_last_name() const
{
  if (last_name.empty()) {
    return std::nullopt;
  } else {
    return last_name;
  }
}

std::ostream&
operator<<(std::ostream& out, const Name& name)
{
  std::string final_string = name.get_forename();

  const auto middle_name = name.get_middle_name();

  if (middle_name) {
    final_string += " " + *middle_name;
  }

  const auto last_name = name.get_last_name();

  if (last_name) {
    final_string += " " + *last_name;
  }

  return out << final_string;
}

}