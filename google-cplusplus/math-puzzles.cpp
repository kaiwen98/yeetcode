/*
    Example 5: Math Puzzles
    One of the powers of computing is being able to do a brute-force search for a solution to a problem. Trial and error works just fine for some problems. In fact, computers can be especially good at such problems. Consider this:

    (1)
    Horses cost $10, pigs cost $3, and rabbits are only $0.50. A farmer buys 100 animals for $100, How many of each animal did he buy? 

    There is a remarkably simple solution to this problem. See if you can find it before you look at ours.

    (2)
    Here is another one to try:
    How many ways can you arrange 6 different books, left to right, on a shelf? 

    This time we will just give you the solution and let you write the program: 720.
*/

#include <iostream>

using namespace std;

void q1Solution() {
    // Brute Force Solution.
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                if ((i + j + k == 100) &&
                    (10*i + 3*j + 0.5*k == 100)) {
                        cout << "Combination: " 
                        << i << " Horses, " 
                        << j << " Pigs, and " 
                        << k << " Rabbits."
                        << endl;
                    }
            }
        }
    }
}

void q2Solution() {
    // Combinatorics Solution.
    // 1 2 3 4 5 6
    // 6 ways to choose the first number.
    // first number can swap with 5 other numbers.
    // next  number can swap with 4 other numbers.
    // ...
    // next  number can swap with 1 other number.
    // Factorial(6) = 720.
    int ans = 1;
    for (int i = 1; i <= 6; i++) {
        ans *= i;
    }
    cout << ans << endl;
}

int main() {
    q1Solution();
    q2Solution();
    return 0;
}