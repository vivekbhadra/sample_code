#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    Student(const std::string& name, int age, double pocket_money, int student_id);

    int get_student_id() const;
    const std::string& get_name() const;
    int get_age() const;
    double get_pocket_money() const;

    void set_name(const std::string& name);
    void set_age(int age);
    void set_pocket_money(double pocket_money);

private:
    std::string name;
    int age;
    double pocket_money;
    int student_id;
};

#endif
