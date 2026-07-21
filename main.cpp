#include <iostream>
class Animal // base class
{
  public:
    virtual void speak() = 0; // pure virtual function making Animal an abstract class
    void set_age(int a);
    {
        age = a;
    }
    int get_age() const
    {
        return age;
    }

  private:
    int age;
};

class Dog : public Animal
{
  public:
    void speak() // overriding the base class method
    {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal
{
  public:
    void speak()
    {
        std::cout << "Cat meows\n";
    }
};

int main()
{
    Dog dog;
    Cat cat;

    dog.speak(); // calls Dog's speak method
    cat.speak(); // calls Cat's speak method

    dog.set_age(5);
    std::cout << "Dog's age: " << dog.get_age() << "\n";
    cat.set_age(3);
    std::cout << "Cat's age: " << cat.get_age() << "\n";

    return 0;
}
