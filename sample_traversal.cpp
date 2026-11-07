#include <iostream>
#include <iterator>

int main()
{
    std::cout << "hello world\n";
    char letters[] {'A', 'B', 'C', '\0'};
    for (int i = 0; letters[i] < '\0'; ++i)
    {
        std::cout << "Manual travelsing: " << letters[i] << "\n";
    }

    return 0;
}
