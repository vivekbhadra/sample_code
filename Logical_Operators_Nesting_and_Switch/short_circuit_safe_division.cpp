#include <iostream>

int main()
{
    double numerator{ 0.0 };
    double divisor{ 0.0 };

    std::cout << "Enter the numerator: ";
    std::cin >> numerator;

    std::cout << "Enter the divisor: ";
    std::cin >> divisor;

    if (divisor != 0.0 && numerator / divisor > 5.0)
    {
        std::cout << "The result is greater than 5.\n";
    }
    else if (divisor == 0.0)
    {
        std::cout << "Division by zero is not permitted.\n";
    }
    else
    {
        std::cout << "The result is 5 or less.\n";
    }

    return 0;
}

