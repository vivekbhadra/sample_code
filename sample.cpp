#include <iostream>

volatile bool flag = false;
int var = 10;
int main()
{
    while (!flag)
    {
        ;
    }

    var = 100;

    return 0;
}