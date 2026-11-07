#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int main()
{
    int x = 10;
    int y = 3;

    std::cout << "Addition: " << add(x, y) << "\n";
    std::cout << "Subtraction: " << subtract(x, y) << "\n";

    return 0;
}
