#ifndef KINO_NAME_HPP
#define KINO_NAME_HPP

#include <ostream>
#include <string>
#include <string_view>

namespace Util {

class Name
{
public:
  explicit Name(std::string_view, std::string_view, std::string_view);

  [[nodiscard]] const std::string& get_forename() const;
  [[nodiscard]] std::pair<const bool, const std::string&> get_middle_name()
    const;
  [[nodiscard]] std::pair<const bool, const std::string&> get_last_name() const;

  friend std::ostream& operator<<(std::ostream&, const Name&);

private:
  const std::string forename;
  const std::string middle_name;
  const std::string last_name;
};

}

#endif