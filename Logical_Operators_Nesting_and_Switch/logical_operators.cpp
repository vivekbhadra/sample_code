#include <iostream>

int main()
{
    int age{ 0 };
    char ticket_reply{ 'n' };
    char banned_reply{ 'n' };
    char special_permission_reply{ 'n' };

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Do you have a ticket? (y/n): ";
    std::cin >> ticket_reply;

    std::cout << "Are you banned? (y/n): ";
    std::cin >> banned_reply;

    std::cout << "Do you have special permission? (y/n): ";
    std::cin >> special_permission_reply;

    const bool has_ticket{ ticket_reply == 'y' || ticket_reply == 'Y' };
    const bool is_banned{ banned_reply == 'y' || banned_reply == 'Y' };
    const bool has_special_permission{
        special_permission_reply == 'y' || special_permission_reply == 'Y'
    };

    const bool standard_entry{ age >= 18 && has_ticket && !is_banned };

    if (standard_entry || has_special_permission)
    {
        std::cout << "Entry permitted.\n";
    }
    else
    {
        std::cout << "Entry denied.\n";
    }

    return 0;
}

