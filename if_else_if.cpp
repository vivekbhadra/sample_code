#include <iostream>

int main()
{
    // positive
    // negetive
    // zero

    char reply{ 'y' };

    int number{ 0 };

    while (reply == 'y')
    {
        std::cout << "Enter a number: ";
        std::cin >> number;

        if (number > 0)
        {
            std::cout << "positive\n\n";
        }
        else if (number < 0)
        {
            std::cout << "negative\n\n";
        }
        else
        {
            std::cout << "zero\n\n";
        }

        std::cout << "Do you want to continue?(y/N)";
        std::cin >> reply;
    }

    return 0;
}