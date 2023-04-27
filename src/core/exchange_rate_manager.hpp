#ifndef KINO_EXCHANGE_RATE_MANAGER_HPP
#define KINO_EXCHANGE_RATE_MANAGER_HPP

#include <cstdlib>
#include <optional>
#include <stdexcept>
#include <vector>

#include "currency.hpp"

namespace Core {

class ExchangeRateManager
{
public:
  [[nodiscard]] static std::optional<double> get_conversion_rate(
    const Currency&,
    const Currency&);

private:
  const static std::vector<std::pair<const Currency, double>>
    exchange_rates_from_usd;
};

}

#endif