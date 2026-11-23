// Example 2: Creating a student database using std::vector.
#include "student_records.h"
#include <iostream>

int main()
{
    const auto students = make_student_database();
    for (const Student& student : students)
    {
        display_student(student);
    }
    std::cout << "Total students: " << students.size() << '\n';
}
