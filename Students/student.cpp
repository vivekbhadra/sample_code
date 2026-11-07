#include "student.h"
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