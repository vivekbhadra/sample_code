#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> numbers;
    int counter{ 0 };

    numbers.fill(++counter);

    for (int &value : numbers)
    {
        value = 10;
        std::cout << value << "\n";
    }

    return 0;
}