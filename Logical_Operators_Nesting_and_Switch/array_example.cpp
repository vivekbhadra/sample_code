#include <iostream>

int main()
{
    int number[10]{ 0 };
    int val = 0;
    char reply{ 'n' };

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Enter a number: ";
        std::cin >> val;
        number[i] = val;
        std::cout << "Do you want to continue? (y/n)";
        std::cin >> reply;
        if (reply == 'n')
            break;
    }

    for (int value : number)
        std::cout << value << " ";
    std::cout << "\n";

    return 0;
}