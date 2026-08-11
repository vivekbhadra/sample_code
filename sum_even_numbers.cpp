#include <iostream>
// sum of even numbers from 1 to n
// Loop: for(i=2; i<=n; i+=2) sum += i;
int sumEven(int n)
{
    if (n < 2)
        return 0;

    if (n % 2 == 1)
        return sumEven(n - 1); // odd n: skip down to even

    return n + sumEven(n - 2); // even n: add it + recurse 10 + sumEven(8)
}
// sumEven(10) -> 2+4+6+8+10 = 30

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    int sum = sumEven(n);
    std::cout << "Sum of even numbers from 1 to " << n << " is: " << sum << "\n";

    return 0;
}
