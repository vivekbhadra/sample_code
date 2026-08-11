#include <iostream>

int main()
{
    int age{ 0 };
    char ticket_reply{ 'n' };

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Do you have a ticket? (y/n): ";
    std::cin >> ticket_reply;

    const bool has_ticket{ ticket_reply == 'y' || ticket_reply == 'Y' };

    if (age >= 18)
    {
        if (has_ticket)
        {
            std::cout << "Entry permitted.\n";
        }
        else
        {
            std::cout << "A ticket is required.\n";
        }
    }
    else
    {
        std::cout << "You must be at least 18.\n";
    }

    return 0;
}

