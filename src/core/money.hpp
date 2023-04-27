#ifndef KINO_MONEY_HPP
#define KINO_MONEY_HPP

#include <cstdlib>
#include <optional>

#include "currency.hpp"
#include "exchange_rate_manager.hpp"

namespace Core {

class Money
{
public:
  Money(Currency, int64_t);

  [[nodiscard]] std::optional<Money> convert_currency_to(Currency) const;
  [[nodiscard]] Currency get_currency() const;
  [[nodiscard]] int64_t get_value() const;
  void add(int64_t);
  void subtract(int64_t);

private:
  Currency currency;
  int64_t value;
};

}

#endif