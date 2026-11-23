/**
 * @file student_database.h
 * @brief Helpers shared by the assignments: build the sample database and
 *        print one record.
 */

#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include "student.h"
#include <cstddef>
#include <vector>

/// Number of students that make_student_database() creates.
inline constexpr std::size_t initial_student_count = 20;

/**
 * @brief Builds the sample database of 20 students (IDs 1001 to 1020).
 *
 * Capacity is reserved up front for exactly ::initial_student_count students,
 * so the vector never reallocates while it is being filled.
 *
 * @note Afterwards `capacity() == size()`, so the caller's next push_back or
 *       emplace_back is guaranteed to reallocate. Assignment 3 relies on this.
 *
 * @return The vector of students. It is returned by value; C++17 copy elision
 *         (NRVO) or a move means nothing is copied.
 */
std::vector<Student> make_student_database();

/**
 * @brief Prints one student on a single line to std::cout.
 *
 * Pocket money is shown with two decimal places. The stream's formatting
 * state is restored afterwards, so later output is not affected.
 *
 * @param student The record to print.
 */
void display_student(const Student& student);

#endif // STUDENT_DATABASE_H
