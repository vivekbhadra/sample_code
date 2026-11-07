#include "Calculator.h"
#include <iostream>
Calculator::Calculator() : factor(0) {};
Calculator::Calculator(int f) : factor{ f }
{
    std::cout << "Constructor called with factor value = " << f << "\n";
}
int Calculator::normalize(int val)
{
    return val * factor;
}

int Calculator::get_factor()
{
    return factor;
}