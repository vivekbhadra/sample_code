#include "student.h"
#include <iostream>
// Student::Student()
// {
//     name = "";
//     age = 0;
//     pocket_money = 0.0;
//     std::cout << "Student constructor called."
//               << "\n";
// }
void Student::set_name(const std::string &name_str)
{
    name = name_str;
}

void Student::set_age(int age_val)
{
    age = age_val;
}

void Student::set_pocket_money(double money_val)
{
    pocket_money = money_val;
}

std::string Student::get_name() const
{
    return name;
}

int Student::get_age() const
{
    return age;
}

double Student::get_pocket_money() const
{
    return pocket_money;
}

// Student::~Student()
// {
//     std::cout << "Student destructor called."
//               << "\n";
// }

GraduateStudent::GraduateStudent()
{
    course_title = "";
    std::cout << "GraduateStudent constructor called."
              << "\n";
}

void GraduateStudent::set_course_title(const std::string &title_str)
{
    course_title = title_str;
}

std::string GraduateStudent::get_course_title() const
{
    return course_title;
}

GraduateStudent::~GraduateStudent()
{
    std::cout << "GraduateStudent destructor called."
              << "\n";
}