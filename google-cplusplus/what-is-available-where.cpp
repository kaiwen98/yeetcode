// scope.cpp, Maggie Johnson
// Description: A program to illustrate different scopes

/*
    Local variable overrides global variables inside function.
    Not good to use global variables because they are hard to track.
*/

#include <iostream>
using namespace std;

int a = 18;
int b = 6;

int function1(int a, int b) {
  return a - b;
}

int function2() {
  int c;
  c = a + b;
  return c;
}

int main() {
  int b = 12;
  int c = 0;
  a = function1(b, a); // a = 12 - 18 = -6. Local scope variables > Global scope variables
  c = function2();     // c = -6 + 6 = 0
  cout << "a: " << a << " b: " << b << " c: " << c << endl; // a = -6, b = 12, c = 0
}