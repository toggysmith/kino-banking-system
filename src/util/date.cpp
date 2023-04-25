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
  return out << date.day << "/" << date.month << "/" << date.year;
}

}