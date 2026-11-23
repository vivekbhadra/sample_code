#include "student.h"

Student::Student(const std::string& name, int age, double pocket_money, int student_id)
    : name(name), age(age), pocket_money(pocket_money), student_id(student_id)
{
}

int Student::get_student_id() const
{
    return student_id;
}

const std::string& Student::get_name() const
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

void Student::set_name(const std::string& new_name)
{
    name = new_name;
}

void Student::set_age(int new_age)
{
    age = new_age;
}

void Student::set_pocket_money(double new_amount)
{
    pocket_money = new_amount;
}
