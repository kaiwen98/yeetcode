/*
    https://developers.google.com/edu/c++/getting-started
    With reference to one of the problem sets.

    The greatest common divisor of two integers is the largest number that divides them both evenly. For example, gcd(12, 18) = 6, gcd(−4, 14) = 2. The most efficient way to compute gcd is with the Euclidean algorithm. Write a program with a function to compute gcd for two integers. Try doing the function without recursion first - it will help you understand how the algorithm works.
    Explicitly define your sub-tasks, for example, find the code for the Euclidean algorithm; create a non-recursive function for the algorithm; etc.
*/

#include <iostream>

using namespace std;

int gcdNonRecursive(int a, int b) {
    int LHS = a, RHS = b, remainder;
    do {
        remainder = LHS % RHS;
        LHS = RHS;
        if (remainder != 0) RHS = remainder;
    } while (remainder != 0);

    return RHS;
}

int gcdRecursive(int a, int b) {
    int remainder = a % b;
    if (remainder == 0) return b;
    else return gcdNonRecursive(b, remainder);
}

int main() {
    cout << gcdRecursive(18, 12) << endl;
    return 0;
}