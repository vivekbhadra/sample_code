#include "student.h"
#include <iostream>
#include <string>

int main()
{
    struct Student s1;
    s1.set_name("Alice");
    s1.set_age(20);
    s1.set_pocket_money(100.50);

    std::cout << "Name: " << s1.get_name() << std::endl;
    std::cout << "Age: " << s1.get_age() << std::endl;
    std::cout << "Pocket Money: $" << s1.get_pocket_money() << std::endl;

    return 0;
}
