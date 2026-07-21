#include <string>
struct Student
{
  public:
    Student() = default;
    //   setter method
    void set_name(const std::string &name_str);
    void set_age(int age_val);
    void set_pocket_money(double money_val);
    // getter method
    std::string get_name() const;
    int get_age() const;
    double get_pocket_money() const;
    ~Student();

  protected:
    std::string name;
    int age;
    double pocket_money;
};

struct GraduateStudent : public Student
{
  public:
    GraduateStudent();
    void set_course_title(const std::string &title_str);
    std::string get_course_title() const;
    ~GraduateStudent();

  protected:
    std::string course_title;
};