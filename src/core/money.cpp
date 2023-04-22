#include "money.hpp"

namespace Core {

Money::Money(Currency currency, int64_t value)
  : currency(currency)
  , value(value)
{
}

std::pair<bool, Money>
Money::convert_currency_to(const Currency newCurrency) const
{
  const auto [success, rate] =
    ExchangeRateManager::get_conversion_rate(currency, newCurrency);

  if (success) {
    return { true, Money{ newCurrency, static_cast<int64_t>(value * rate) } };
  } else {
    return { false, *this };
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