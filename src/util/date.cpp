#include "date.hpp"

namespace Util {

Date::Date(const int day, const int month, const int year)
  : day(day)
  , month(month)
  , year(year)
{
}

std::ostream&
operator<<(std::ostream& out, const Date& date)
{
  std::string date_str;

  if (date.day < 10) {
    date_str += "0";
  }

  date_str += std::to_string(date.day);
  date_str += "/";

  if (date.month < 10) {
    date_str += "0";
  }

  date_str += std::to_string(date.month);
  date_str += "/";
  date_str += std::to_string(date.year);

  return out << date_str;
}

}