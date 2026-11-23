/**
 * @file student.h
 * @brief Declares the Student class, a single record in the student database.
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

/**
 * @class Student
 * @brief A student's identity and basic details.
 *
 * The student ID is fixed once the object is built, so it has no setter.
 * The ID is what lookups match on, so it should not change after the record
 * is stored. Name, age and pocket money can be updated through setters.
 */
class Student
{
public:
    /**
     * @brief Builds a student record.
     * @param name         Full name of the student.
     * @param age          Age in years.
     * @param pocket_money Weekly pocket money, in pounds.
     * @param student_id   Unique identifier used to look the student up.
     */
    Student(const std::string& name, int age, double pocket_money, int student_id);

    /** @brief Returns the student's unique ID. */
    int get_student_id() const;

    /**
     * @brief Returns the student's name.
     * @return A const reference, so the string is not copied. The reference
     *         stays valid only while this Student object exists and is not
     *         moved, for example by a std::vector reallocation.
     */
    const std::string& get_name() const;

    /** @brief Returns the student's age in years. */
    int get_age() const;

    /** @brief Returns the student's pocket money. */
    double get_pocket_money() const;

    /** @brief Replaces the student's name. @param name New name. */
    void set_name(const std::string& name);

    /** @brief Updates the student's age. @param age New age in years. */
    void set_age(int age);

    /** @brief Updates the student's pocket money. @param pocket_money New amount. */
    void set_pocket_money(double pocket_money);

private:
    std::string name;    ///< Full name.
    int age;             ///< Age in years.
    double pocket_money; ///< Pocket money (double is fine here; real money code would use integer pence).
    int student_id;      ///< Unique key, fixed when the object is built.
};

#endif // STUDENT_H
