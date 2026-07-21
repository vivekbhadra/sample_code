#include <iostream>

void foo(int value);
// glabal variable
int value; // initialised by 0

int main()
{
    int var = 20;       // stack variable - not guaranteed to be initialised by 0
    int *ptr = nullptr; // uninitialised pointer
    ptr = &var;         // initialising the pointer
    std::cout << "Value of var = " << var << "\n";
    std::cout << "value of var via ptr = " << *ptr << "\n";

    int x = 20;
    ptr = &x; // reinitialising the pointer to point to a new variable
    std::cout << "value of x via ptr = " << *ptr << "\n";

    int y = 300;
    ptr = &y;
    std::cout << "value of y via ptr = " << *ptr << "\n";

    return 0;
}

void foo(int value)
{
    std::cout << value << "\n";
}