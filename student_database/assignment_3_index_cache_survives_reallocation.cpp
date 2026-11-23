/**
 * @file assignment_3_index_cache_survives_reallocation.cpp
 * @brief Assignment 3: a one-entry lookup cache that stays valid after the
 *        vector reallocates.
 *
 * Why the cache stores an index, not an iterator
 * ----------------------------------------------
 * When a std::vector grows past its capacity, it allocates a new buffer,
 * moves every element into it and frees the old buffer. After that, every
 * iterator, pointer and reference into the vector is invalidated. Using one
 * is undefined behaviour: it may appear to work, print garbage or crash.
 *
 * An index is a position, not an address, so `students[i]` finds the same
 * element after a reallocation. Appending at the end never changes an
 * existing element's index.
 *
 * make_student_database() reserves exactly 20 slots and fills all 20, so the
 * first emplace_back below is guaranteed to reallocate. That is exactly the
 * case where a cached iterator would dangle and a cached index does not.
 * The program prints the buffer address before and after so the
 * reallocation can be seen.
 *
 * @note An index is safe for appending only. Inserting or erasing before the
 *       cached position shifts elements, so the index would point at a
 *       different student. find_student() therefore checks that the ID at
 *       the cached index still matches before it reports a hit.
 */

#include "student_database.h"
#include <cstddef>
#include <iostream>
#include <optional>
#include <vector>

/**
 * @brief Finds a student by ID, checking a one-entry cache first.
 *
 * The cache is used only if it is set, is within range and still holds the
 * requested ID. Otherwise the vector is searched from the start, which costs
 * O(n), and the cache is updated with the result.
 *
 * @param students     The database to search.
 * @param student_id   The ID to look for.
 * @param cached_index In/out: the index of the last successful lookup. It is
 *                     set on a match and cleared when the ID is not found.
 * @return The index of the matching student, or std::nullopt if no student
 *         has that ID.
 */
std::optional<std::size_t> find_student(const std::vector<Student>& students,
                                        int student_id,
                                        std::optional<std::size_t>& cached_index)
{
    // The bounds and ID checks keep a stale cache from causing an
    // out-of-range access or a wrong match.
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

/**
 * @brief Looks a student up, appends more students (forcing a reallocation),
 *        then looks the same student up again through the cache.
 * @return 0 on success, 1 if the requested student is missing.
 */
int main()
{
    // Not const: students are appended and one name is changed below.
    auto students = make_student_database();
    std::optional<std::size_t> cached_index;
    const int requested_id = 1013;

    // First lookup: the cache is empty, so this searches and fills it.
    const auto first = find_student(students, requested_id, cached_index);
    if (!first)
    {
        std::cerr << "Student not found\n";
        return 1;
    }
    display_student(students[*first]);

    std::cout << "Before appending: size " << students.size()
              << ", capacity " << students.capacity()
              << ", buffer at " << static_cast<const void*>(students.data()) << '\n';

    // size == capacity here, so the first append reallocates. Every element
    // moves to a new buffer, but each one keeps its index.
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

    std::cout << "After appending:  size " << students.size()
              << ", capacity " << students.capacity()
              << ", buffer at " << static_cast<const void*>(students.data()) << '\n';

    // Second lookup: the cached index is still correct, so this is a hit.
    const auto second = find_student(students, requested_id, cached_index);
    if (!second)
    {
        std::cerr << "Student not found\n";
        return 1;
    }

    // Take the reference only now, after the last append. A reference taken
    // before the appends would point into the freed buffer.
    Student& student = students[*second];
    student.set_name("Maya Shah");
    display_student(student);
}
