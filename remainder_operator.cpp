#include <iostream>

int main()
{
    int number{};
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number % 2 == 0)
    {
        std::cout << number << " is even.\n\n";
    }
    else
    {
        std::cout << number << " is odd.\n\n";
    }

    return 0;
}