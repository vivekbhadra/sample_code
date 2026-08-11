#include <iostream>

static int my_function()
{
    static int counter = 0;

    return ++counter;
}