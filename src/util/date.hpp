#ifndef KINO_DATE_HPP
#define KINO_DATE_HPP

#include <ostream>

namespace Util {

class Date
{
public:
  explicit Date(int, int, int);

  friend std::ostream& operator<<(std::ostream& out, const Date&);

private:
  const int day;
  const int month;
  const int year;
};

}

#endif