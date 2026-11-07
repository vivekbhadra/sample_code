#include <cstring>
#include <iostream>

int main()
{
    char name[6]{ "Alice" };

    for (int i = 0; name[i] != '\0'; ++i)
    {
        std::cout << name[i] << " ";
    }

    std::cout << "\n";

    return 0;
}