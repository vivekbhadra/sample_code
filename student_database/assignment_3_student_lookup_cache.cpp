// Example 3: Finding a student using a one-entry lookup cache.
#include "student_records.h"
#include <cstddef>
#include <iostream>
#include <optional>

std::optional<std::size_t> find_student(const std::vector<Student>& students,
                                        int student_id,
                                        std::optional<std::size_t>& cached_index)
{
    if (cached_index && *cached_index < students.size()
        && students[*cached_index].get_student_id() == student_id)
    {
        std::cout << "Cache hit for ID " << student_id << '\n';
        return cached_index;
    }

    std::cout << "Searching the vector for ID " << student_id << '\n';
    for (std::size_t index = 0; index < students.size(); ++index)
    {
        if (students[index].get_student_id() == student_id)
        {
            cached_index = index;
            return index;
        }
    }
    cached_index.reset();
    return std::nullopt;
}

int main()
{
    auto students = make_student_database();
    // Appending can move the elements, but it preserves their indices.
    std::optional<std::size_t> cached_index;
    const int requested_id = 1013;

    const auto first = find_student(students, requested_id, cached_index);
    if (!first)
    {
        std::cerr << "Student not found\n";
        return 1;
    }
    display_student(students[*first]);

    students.emplace_back("Uma Gill", 19, 15.00, 1021);
    students.emplace_back("Vera Bell", 18, 12.50, 1022);
    students.emplace_back("Will Ford", 20, 18.00, 1023);
    students.emplace_back("Xia Wang", 19, 20.00, 1024);
    students.emplace_back("Yara Noor", 18, 11.00, 1025);
    students.emplace_back("Zoe Gray", 20, 16.50, 1026);
    students.emplace_back("Arun Sen", 19, 14.00, 1027);
    students.emplace_back("Beth Day", 18, 13.00, 1028);
    students.emplace_back("Cora West", 20, 19.50, 1029);
    students.emplace_back("Dan Page", 19, 17.00, 1030);
    std::cout << "Total students: " << students.size() << '\n';

    const auto second = find_student(students, requested_id, cached_index);
    if (!second)
    {
        std::cerr << "Student not found\n";
        return 1;
    }

    Student& student = students[*second];
    student.set_name("Maya Shah");
    display_student(student);
}
