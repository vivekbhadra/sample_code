#include <iostream>

// Function declarations
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

        std::cout << "Enter the first number: ";
        std::cin >> firstNumber;

        std::cout << "Enter the second number: ";
        std::cin >> secondNumber;

        if (choice == 1)
        {
            // TODO: Call the addition function and display the result.
        }
        else if (choice == 2)
        {
            // TODO: Call the subtraction function and display the result.
        }
        else if (choice == 3)
        {
            // TODO: Call the multiplication function and display the result.
        }
        else if (choice == 4)
        {
            // TODO: Check for division by zero.
            // TODO: Call the division function and display the result.
        }
        else
        {
            // TODO: Display an invalid menu selection message.
        }

        std::cout << "\nWould you like to perform another calculation? (y/n): ";
        std::cin >> reply;

    } while (/* TODO: Continue when reply is 'y' or 'Y' */);

    std::cout << "\nCalculator closed.\n";

    return 0;
}

double add(double firstNumber, double secondNumber)
{
    // TODO: Return the sum.
    return 0.0;
}

double subtract(double firstNumber, double secondNumber)
{
    // TODO: Return the difference.
    return 0.0;
}

double multiply(double firstNumber, double secondNumber)
{
    // TODO: Return the product.
    return 0.0;
}

double divide(double firstNumber, double secondNumber)
{
    // TODO: Return the result of division.
    return 0.0;
}