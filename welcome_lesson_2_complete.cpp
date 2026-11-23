
#include <iostream>
#include <string>

// Function that takes an integer and returns a bool
bool is_adult(int age)
{
    return age >= 18;
}

// Function that takes two parameters
void welcome_message(std::string name, int age)
{
    std::cout << "Welcome " << name << "\n";

    if (is_adult(age))
    {
        std::cout << "You are an adult.\n";
    }
    else
    {
        std::cout << "You are under 18.\n";
    }
}

int main()
{
    // 1. Variables and data types

    int age{};
    double price{ 12.50 };
    bool registered{ true };
    std::string name;

    // 2. Reading user input

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    std::cin >> age;

    // 3. Printing variables

    std::cout << "\nStudent Information\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Registered: " << registered << "\n";

    // 4. Arithmetic operators

    std::cout << "\nArithmetic\n";

    int next_age{ age + 1 };
    int previous_age{ age - 1 };

    std::cout << "Age next year: " << next_age << "\n";
    std::cout << "Age last year: " << previous_age << "\n";

    double total{ price * 2 };

    std::cout << "Price: " << price << "\n";
    std::cout << "Price for two: " << total << "\n";

    // Integer division and remainder

    int a{ 5 };
    int b{ 2 };

    std::cout << "5 / 2 = " << a / b << "\n";
    std::cout << "5 % 2 = " << a % b << "\n";
    std::cout << "5.0 / 2 = " << 5.0 / b << "\n";

    // 5. Comparison operators

    std::cout << "\nComparisons\n";

    std::cout << "age == 18: " << (age == 18) << "\n";
    std::cout << "age != 18: " << (age != 18) << "\n";
    std::cout << "age < 18: " << (age < 18) << "\n";
    std::cout << "age > 18: " << (age > 18) << "\n";
    std::cout << "age <= 18: " << (age <= 18) << "\n";
    std::cout << "age >= 18: " << (age >= 18) << "\n";

    // Comparisons produce bool values.
    // By default, cout prints true as 1 and false as 0.

    // 6. Storing a comparison result in a bool

    bool adult{ is_adult(age) };

    std::cout << "\nAdult status: " << adult << "\n";

    // 7. Making decisions with if and else

    std::cout << "\nChecking age\n";

    if (age >= 18)
    {
        std::cout << "Age is at least 18.\n";
    }
    else
    {
        std::cout << "Age is below 18.\n";
    }

    // 8. Calling a function with parameters

    std::cout << "\nCalling welcome_message()\n";

    welcome_message(name, age);

    // 9. Repeating function calls using a for loop

    std::cout << "\nRepeating the welcome message\n";

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Iteration: " << i << "\n";
        welcome_message(name, age);
    }

    return 0;
}
