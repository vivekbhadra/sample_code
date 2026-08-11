#include <iostream>

int my_var = 10;
int my_second_var; // default initlaised to 0 (BSS - Block Started by Symbol)

double calculate_area(int radius)
{
    double PI{ 3.14 };
    int var_func;

    std::cout << var_func * PI << "\n";
    return PI * radius * radius;
}

int main()
{
    double area = calculate_area(5);
    std::cout << "Area of the circle: " << area << "\n\n";

    return 0;
}