#include <iostream>

int division(int numerator, int divisor)
{
    return (divisor != 0 && numerator / divisor > 5);
}

int main()
{
    int result = division(100, 10);
    std::cout << "result = " << result << "\n\n";

    return 0;
}
