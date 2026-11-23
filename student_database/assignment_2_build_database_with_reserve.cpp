/**
 * @file assignment_2_build_database_with_reserve.cpp
 * @brief Assignment 2: build a student database in a std::vector and list it.
 *
 * Points to notice:
 *  - make_student_database() calls reserve() before adding students, so the
 *    vector allocates once instead of growing step by step. See
 *    student_database.cpp for the reasoning.
 *  - The size is equal to the capacity once the database is built (both 20).
 *  - The range-based for loop binds `const Student&`, so no Student is copied
 *    while the list is printed.
 */

#include "student_database.h"
#include <iostream>

/**
 * @brief Builds the database, prints every student, then prints the count.
 * @return 0 on success.
 */
int main()
{
    // const: this program only reads the database.
    const auto students = make_student_database();

    for (const Student& student : students)
    {
        display_student(student);
    }

    std::cout << "Total students: " << students.size()
              << " (capacity: " << students.capacity() << ")\n";
}
