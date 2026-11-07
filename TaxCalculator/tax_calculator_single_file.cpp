#include <iostream>

class TaxCalculator
{
  public:
    TaxCalculator() = default;
    explicit TaxCalculator(int rate);
    int price_with_tax(int net_price) const;
    int get_rate() const;

  private:
    int rate_percent{ 20 };
};

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

int main()
{
    TaxCalculator calc;
    std::cout << "Rate: " << calc.get_rate() << "%\n";
    std::cout << "Price with tax: " << calc.price_with_tax(1000) << "\n";

    TaxCalculator reduced(5);
    std::cout << "Rate: " << reduced.get_rate() << "%\n";
    std::cout << "Price with tax: " << reduced.price_with_tax(1000) << "\n";

    return 0;
}
