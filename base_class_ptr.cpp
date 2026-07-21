#include <iostream>

class Base
{
  public:
    virtual void display()
    {
        std::cout << "Base class display function\n";
    }
    virtual ~Base()
    {
    } // virtual destructor to ensure proper cleanup of derived class objects
};

class Derived : public Base
{
  public:
    void display() override // overriding the base class method
    {
        std::cout << "Derived class display function\n";
    }
};

class Derived2 : public Base
{
  public:
    void display() override // overriding the base class method
    {
        std::cout << "Derived2 class display function\n";
    }
};

int main()
{
    Base *ptr = new Derived();
    ptr->display();

    delete ptr; // free the allocated memory
    ptr = new Derived2();
    ptr->display();
    delete ptr; // free the allocated memory

    return 0;
}