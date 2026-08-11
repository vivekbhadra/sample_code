#include <iostream>

int main()
{
    int choice{ 0 };
    double number_1{ 0.0 };
    double number_2{ 0.0 };

    std::cout << "Calculator\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice >= 1 && choice <= 4)
    {
        std::cout << "Enter two numbers: ";
        std::cin >> number_1 >> number_2;
    }

    switch (choice)
    {
        case 1:
            std::cout << "Result = " << number_1 + number_2 << '\n';
            break;

        case 2:
            std::cout << "Result = " << number_1 - number_2 << '\n';
            break;

        case 3:
            std::cout << "Result = " << number_1 * number_2 << '\n';
            break;

        case 4:
            if (number_2 != 0.0)
            {
                std::cout << "Result = " << number_1 / number_2 << '\n';
            }
            else
            {
                std::cout << "Division by zero is not permitted.\n";
            }
            break;

        default:
            std::cout << "Invalid menu selection.\n";
            break;
    }

    return 0;
}

