#include "exchange_rate_manager.hpp"

namespace Core {

const std::vector<std::pair<const Currency, double>>
  ExchangeRateManager::exchange_rates_from_usd = {
    { Currency::eur, 0.90114662 }, { Currency::jpy, 6708.1971 },
    { Currency::gbp, 0.8041834 },  { Currency::cny, 344.67891 },
    { Currency::aud, 74.719182 },  { Currency::cad, 68.334826 },
    { Currency::chf, 44.647059 },  { Currency::hkd, 392.50372 },
    { Currency::sgd, 66.753971 }
  };

std::pair<bool, double>
ExchangeRateManager::get_conversion_rate(const Currency& current_currency,
                                         const Currency& desired_currency)
{
  bool is_converting_from_usd = (current_currency == Currency::usd);

  if (is_converting_from_usd) {
    for (auto exchange_rate : exchange_rates_from_usd) {
      auto [to_currency, rate] = exchange_rate;

      if (to_currency == desired_currency) {
        return { true, rate };
      }
    }
  } else {
    for (auto exchange_rate : exchange_rates_from_usd) {
      auto [to_currency, rate] = exchange_rate;

      if (to_currency == current_currency) {
        return { true, 1 / rate };
      }
    }
  }

  // INFO: We only reach this point if there wasn't an exchange rate found. This
  // isn't necessarily fatal because the banking system may just not support
  // exchanging from / to the given currencies, but the method should be clearly
  // indicated as having been unsuccessful.
  return { false, 0 };
}

}