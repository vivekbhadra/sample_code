#include "student_records.h"
#include <iomanip>
#include <iostream>

std::vector<Student> make_student_database()
{
    std::vector<Student> students;
    students.reserve(20);
    students.emplace_back("Amira Ali", 19, 15.00, 1001);
    students.emplace_back("Ben Scott", 18, 12.50, 1002);
    students.emplace_back("Chloe Adams", 20, 20.00, 1003);
    students.emplace_back("Dev Shah", 19, 14.50, 1004);
    students.emplace_back("Eva Brown", 18, 18.00, 1005);
    students.emplace_back("Finn Jones", 19, 10.00, 1006);
    students.emplace_back("Grace Lee", 20, 22.50, 1007);
    students.emplace_back("Hugo Evans", 18, 12.00, 1008);
    students.emplace_back("Isha Roy", 19, 16.00, 1009);
    students.emplace_back("Jack Hall", 20, 15.50, 1010);
    students.emplace_back("Kai Chen", 18, 19.00, 1011);
    students.emplace_back("Lily Wood", 19, 13.00, 1012);
    students.emplace_back("Maya Patel", 20, 17.50, 1013);
    students.emplace_back("Noah King", 18, 21.00, 1014);
    students.emplace_back("Omar Khan", 19, 14.00, 1015);
    students.emplace_back("Pia Cole", 20, 11.50, 1016);
    students.emplace_back("Quinn Reed", 18, 16.50, 1017);
    students.emplace_back("Rosa Diaz", 19, 18.50, 1018);
    students.emplace_back("Sam Hill", 20, 13.50, 1019);
    students.emplace_back("Tara Lane", 18, 20.50, 1020);
    return students;
}

void display_student(const Student& student)
{
    std::cout << "ID: " << student.get_student_id()
              << " | Name: " << student.get_name()
              << " | Age: " << student.get_age()
              << " | Pocket money: " << std::fixed << std::setprecision(2)
              << student.get_pocket_money() << '\n';
}
