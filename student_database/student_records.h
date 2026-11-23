#ifndef STUDENT_RECORDS_H
#define STUDENT_RECORDS_H

#include "student.h"
#include <vector>

std::vector<Student> make_student_database();
void display_student(const Student& student);

#endif
