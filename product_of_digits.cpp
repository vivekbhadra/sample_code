#include <iostream>
// product of digits (not sum)
// Loop: while(n>0) { result *= n%10; n/=10; }
int productDigits(int n)
{
    if (n < 10)
        return n; // single digit: return it
    return (n % 10) * productDigits(n / 10);
}
// productDigits(234) -> 2*3*4 = 24
// 234 % 10 = 4, 234 / 10 = 23
// 23 % 10 = 3, 23 / 10 = 2
// % is remainder operator, / is integer division

int main()
{
    int n = 234;

    int product = productDigits(n);
    std::cout << "Product of digits of " << n << " is: " << product << "\n";

    return 0;
}