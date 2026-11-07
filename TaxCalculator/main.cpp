#include "TaxCalculator.h"
#include <iostream>

int main()
{
    TaxCalculator calc;
    std::cout << calc.get_rate() << "\n";

    return 0;
}
