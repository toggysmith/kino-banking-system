#include "money.hpp"

namespace Core {

Money::Money(Currency currency, int64_t value)
  : currency(currency)
  , value(value)
{
}

std::optional<Money>
Money::convert_currency_to(const Currency newCurrency) const
{
  const auto rate =
    ExchangeRateManager::get_conversion_rate(currency, newCurrency);

  if (rate) {
    return Money{ newCurrency, value * static_cast<int64_t>(*rate) };
  } else {
    return std::nullopt;
  }
}

Currency
Money::get_currency() const
{
  return currency;
}

int64_t
Money::get_value() const
{
  return value;
}

void
Money::add(const int64_t additionalAmount)
{
  value += additionalAmount;
}

void
Money::subtract(const int64_t subtractAmount)
{
  value -= subtractAmount;
}

}