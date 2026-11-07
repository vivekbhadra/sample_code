#include <iostream>

int main()
{
    int age{ 0 };
    char accompanied_by_adult{ 'n' };

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter if you have a ticket? (y/n): ";
    std::cin >> accompanied_by_adult;

    if (age >= 12 || accompanied_by_adult == 'y') // 12A
    {
        std::cout << "You are allowed to enter the movie hall\n";
    }
    else
    {
        std::cout << "You are not allowed to enter the movie hall\n";
    }

    return 0;
}