#include <iostream>

int main()
{
    char reply{ 'n' };

    std::cout << "Do you want to continue? (y/n): ";
    std::cin >> reply;

    switch (reply)
    {
        case 'y':
        case 'Y':
            std::cout << "Continuing...\n";
            break;

        case 'n':
        case 'N':
            std::cout << "Stopping...\n";
            break;

        default:
            std::cout << "Invalid response.\n";
            break;
    }

    return 0;
}
