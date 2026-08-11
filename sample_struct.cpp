#include <iostream>
#include <string>

struct StudentInfo
{
    std::string name;
    int student_id;
    std::string course;
    std::string uni_name;
    double pocket_money;
};

int add_numbers(int x, int y)
{
    int result;
    int var1;
    int var2;

    var1 = x;
    var2 = y;

    result = var1 + var2;
    return result;
}

int main()
{
    int value = add_numbers(20, 30);
    std::cout << value << "\n";

    value = add_numbers(50, 40);
    std::cout << value << "\n";

    while (1)
    {
        struct StudentInfo myStudent;
        char reply;
        std::cout << "Enter Student's Name: ";
        std::cin >> myStudent.name;
        std::cout << "Enter Student's ID: ";
        std::cin >> myStudent.student_id;
        std::cout << "Enter Student's Course: ";
        std::cin >> myStudent.course;
        std::cout << "Enter Student's University: ";
        std::cin >> myStudent.uni_name;
        std::cout << "Enter Student's Pocket Money: ";
        std::cin >> myStudent.pocket_money;

        std::cout << "\n";
        std::cout << "Stdudent's Name = " << myStudent.name << "\n";
        std::cout << "Stdudent's ID = " << myStudent.student_id << "\n";
        std::cout << "Stdudent's Course = " << myStudent.course << "\n";
        std::cout << "Stdudent's UniName = " << myStudent.uni_name << "\n";
        std::cout << "Stdudent's Pocket Money = " << myStudent.pocket_money << "\n";

        std::cout << "\n";
        bool valid_input = false;
        while (!valid_input)
        {
            std::cout << "Do you want to continue?(y/N) ";
            std::cin >> reply;

            if (reply == 'y' || reply == 'N')
            {
                valid_input = true;
            }
        }
        if (reply == 'N')
        {
            break;
        }
    }

    return 0;
}