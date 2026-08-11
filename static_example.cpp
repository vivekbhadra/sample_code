#include <iostream>
extern int my_function();

int main()
{
    int i = 0;
    while (++i < 5)
    {
        int count = my_function();
        std::cout << "count = " << count << "\n";
    }

    return 0;
}