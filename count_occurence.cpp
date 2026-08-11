#include <iostream>

// count occurrences of a digit in a number
int countDigitOccurrence(int n, int digit)
{
    if (n == 0)
        return 0;
    int match = (n % 10 == digit) ? 1 : 0;
    return match + countDigitOccurrence(n / 10, digit);
}
// countDigitOccurrence(11211, 1) -> 4

// int countDigitOccurrenceLoop(int n, int digit)
// {
//     int count = 0;
//     while (n > 0)
//     {
//         int digit_in_unit_position = n % 10; // 11211 % 10 = 1
//         if (digit_in_unit_position == digit)
//             count++;
//         n /= 10;
//     }
//     return count;
// }

int main()
{
    int n = 11211;
    int digit = 1;

    // % --> remainder operator, / --> integer division
    int count = countDigitOccurrence(n, digit);
    std::cout << "Count of digit " << digit << " in number " << n << " is: " << count << "\n";

    return 0;
}