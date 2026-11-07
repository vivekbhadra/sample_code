#include "TaxCalculator.h"
#include <iostream>

TaxCalculator::TaxCalculator(int rate) : rate_percent{ rate }
{
    std::cout << "Constructor called with rate = " << rate << "\n";
}

int TaxCalculator::price_with_tax(int net_price) const
{
    return net_price + net_price * rate_percent / 100;
}

int TaxCalculator::get_rate() const
{
    return rate_percent;
}
