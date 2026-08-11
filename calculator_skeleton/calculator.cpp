#include <iostream>

double add(double firstNumber, double secondNumber);
double subtract(double firstNumber, double secondNumber);
double multiply(double firstNumber, double secondNumber);
double divide(double firstNumber, double secondNumber);

int main()
{
    int choice{};
    double firstNumber{};
    double secondNumber{};
    char reply{};

    do
    {
        std::cout << "\nSimple Calculator\n\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n\n";

        std::cout << "Select an operation: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            std::cout << "Enter the first number: ";
            std::cin >> firstNumber;

            std::cout << "Enter the second number: ";
            std::cin >> secondNumber;
        }

        if (choice == 1)
        {
            std::cout << "\nResult: " << firstNumber << " + " << secondNumber << " = " << add(firstNumber, secondNumber)
                      << '\n';
        }
        else if (choice == 2)
        {
            std::cout << "\nResult: " << firstNumber << " - " << secondNumber << " = "
                      << subtract(firstNumber, secondNumber) << '\n';
        }
        else if (choice == 3)
        {
            std::cout << "\nResult: " << firstNumber << " * " << secondNumber << " = "
                      << multiply(firstNumber, secondNumber) << '\n';
        }
        else if (choice == 4)
        {
            if (secondNumber == 0.0)
            {
                std::cout << "\nError: Division by zero is not allowed.\n";
            }
            else
            {
                std::cout << "\nResult: " << firstNumber << " / " << secondNumber << " = "
                          << divide(firstNumber, secondNumber) << '\n';
            }
        }
        else
        {
            std::cout << "\nError: Invalid menu selection.\n";
        }

        std::cout << "\nWould you like to perform another calculation? (y/n): ";
        std::cin >> reply;

    } while (reply == 'y' || reply == 'Y');

    std::cout << "\nCalculator closed.\n";

    return 0;
}

double add(double firstNumber, double secondNumber)
{
    return firstNumber + secondNumber;
}

double subtract(double firstNumber, double secondNumber)
{
    return firstNumber - secondNumber;
}

double multiply(double firstNumber, double secondNumber)
{
    return firstNumber * secondNumber;
}

double divide(double firstNumber, double secondNumber)
{
    return firstNumber / secondNumber;
}