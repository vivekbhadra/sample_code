#include <iostream>
#include <string>
#include <string>

// like a calss
// Struct members are by default public
struct Students
{
    public:
        // setter
        void set_name(std::string& name) { name = name;}
        void set_age(int age) { age = age;}
        void set_pocket_money(double pm) { pocket_money = pm;}
        void set_grade(std::string& grade) { grade = grade; }

        // getter
        std::string get_name() { return name;}
        int get_age() { return age;}
        double get_pocket_money() { return pocket_money;}
        std::string get_grade() { return grade; }
    private:
        std::string name;
        int age;
        double pocket_money;
        std::string grade;
};

// called by the OS
int main()
{
    Students s1;
    std::string name = "Linda";
    s1.set_name(name);
    s1.set_age(18);
    s1.set_pocket_money(100.00);
    std::string grade = "A++";
    s1.set_grade(grade);

    std::cout << "Name: "<< s1.get_name() << "\n" \
              << "Age: " << s1.get_age() << "\n" \
              << "Pocket Money: " << s1.get_pocket_money() << "\n" \
              << "Grade: " << s1.get_grade() << "\n";

    return 0;
}
