#include "exchange_rate_manager.hpp"

namespace Core {

const std::vector<std::pair<const Currency, double>>
  ExchangeRateManager::exchange_rates_from_usd = {
    { Currency::eur, 0.90114662 }, { Currency::jpy, 134.12806 },
    { Currency::gbp, 0.8041834 },  { Currency::cny, 6.8880315 },
    { Currency::aud, 1.4933738 },  { Currency::cad, 1.3596194 },
    { Currency::chf, 0.89232983 }, { Currency::hkd, 7.8487124 },
    { Currency::sgd, 1.3347096 }
  };

std::optional<double>
ExchangeRateManager::get_conversion_rate(const Currency& current_currency,
                                         const Currency& desired_currency)
{
  // Option 1: We are doing USD -> X exchange. I.e. we have the exchange to the
  // desired currency explicitly stored.
  bool is_usd_to_other = (current_currency == Currency::usd);

  if (is_usd_to_other) {
    for (auto exchange_rate : exchange_rates_from_usd) {
      auto [to_currency, rate] = exchange_rate;

      if (to_currency == desired_currency) {
        return rate;
      }
    }
  }
  // Option 2: We are doing X -> USD exchange. I.e. we don't have the exchange
  // rate to the desired currency explicit stored, but we can get the reciprocal
  // to work it out.
  bool is_other_to_usd = (desired_currency == Currency::usd);

  if (is_other_to_usd) {
    for (auto exchange_rate : exchange_rates_from_usd) {
      auto [to_currency, rate] = exchange_rate;

      if (to_currency == current_currency) {
        return 1.0 / rate;
      }
    }
  }

  // Option 3: We are doing X -> Y exchange. I.e. we don't have the exchange
  // rates for either currency explicitly stored.

  // Get exchange rate of current currency to USD
  const auto current_currency_to_usd_rate =
    get_conversion_rate(current_currency, Currency::usd);

  if (!current_currency_to_usd_rate) {
    return std::nullopt;
  }

  // Get exchange rate of USD to the desired currency
  const auto usd_to_desired_currency_rate =
    get_conversion_rate(Currency::usd, desired_currency);

  if (!usd_to_desired_currency_rate) {
    return std::nullopt;
  }

  // Multiply the two exchange rates together to get the final exchange rate
  return (*current_currency_to_usd_rate) * (*usd_to_desired_currency_rate);
}

}