#ifndef TAX_CALCULATOR_H
#define TAX_CALCULATOR_H

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

#endif // TAX_CALCULATOR_H
