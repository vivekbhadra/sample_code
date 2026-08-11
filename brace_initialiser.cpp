#include <iostream>

int var;

int main()
{
    int age{ 0 }; // using brace initialization to initialize age
    bool is_adult{ age >= 18 };

    std::cout << "Enter your age: "; // 25
    std::cin >> age;                 // read age from user input
    is_adult = age >= 18;

    // ==
    // !=
    if (true) // is_adult = true
    {
        std::cout << "You are not an adult.\n";
        int var = 100 + 300;
        std::cout << "The value of var = " << var << "\n";
    }
    else
    {
        std::cout << "You are an adult.\n";
    }

    std::cout << std::boolalpha; // print bool values as true/false instead of 1/0
    std::cout << "The person is an adult: " << is_adult << "\n\n\n";

    return 0;
}
