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

int main()
{

    while (1)
    {
        char reply;
        struct StudentInfo myStudent;
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
        std::cout << "Do you want to continue?(y/n): ";
        std::cin >> reply;
        if (reply == 'n')
        {
            break;
        }
    }

    return 0;
}