#include <iostream>

int main()
{
    char response{ 'n' };
    std::cout << "Do you want to continue? (y/n)";
    std::cin >> response;

    switch (response)
    {
    case 'y':
    case 'Y':
        std::cout << "User wants to continue." << '\n';
        break;

    case 'n':
    case 'N':
        std::cout << "User doesn't want to continue." << '\n';
        break;

    default:
        std::cout << "Invalid menu selection.\n";
        break;
    }

    return 0;
}
