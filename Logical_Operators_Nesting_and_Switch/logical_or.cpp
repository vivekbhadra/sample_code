#include <iostream>
#include <string>

int main()
{
    int age{ 0 };
    std::string name;
    int student_id{ 0 };
    char is_cpatain{ 'n' };
    while (1)
    {
        std::cout << "Enter your name: ";
        std::cin >> name;

        std::cout << "Enter your age: ";
        std::cin >> age;

        std::cout << "Enter Your Student ID:";
        std::cin >> student_id;

        std::cout << "Are you the captain of the team? (y/n):";
        std::cin >> is_cpatain;

        if (age >= 18 && (student_id > 100 && student_id < 200) || (is_cpatain == 'y'))
        {
            std::cout << "You are allowed to enter the Library\n\n";
        }
        else
        {
            std::cout << "You are not allowed to enter the library\n\n";
        }
    }

    return 0;
}