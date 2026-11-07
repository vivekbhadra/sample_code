#include <string>
struct Student
{
  public:
    Student() = default;
    // setter method
    void set_name(const std::string &name_str);
    void set_age(int age_val);
    void set_pocket_money(double money_val);
    // getter method
    std::string get_name() const;
    int get_age() const;
    double get_pocket_money() const;

  private:
    std::string name;
    int age;
    double pocket_money;
};