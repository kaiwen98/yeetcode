#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

bool soln1(char* inp) {
    char* first = inp;
    char* last = inp + strlen(inp) - 1;
    int count = 0;
    while (*first == *last) {     
        cout << *first << endl << *last << endl;
        first++;
        last--;
        count++;
        if (count == strlen(inp) / 2) {
            return true;
        }
    }
    return false;
}

bool soln2(int inp) {
    int left;
    int right;
    int count = 0;
    int remainder = inp;
    int inp_len = 1;

    while (remainder) inp_len += ((remainder = remainder/10) != 0);
    // cout << inp_len << endl;
    remainder = inp;
    while (inp_len > 1) {
        
        left = remainder / (pow(10, inp_len - 1));
        right = remainder % 10;

        // cout << left << endl << right << endl << remainder << endl;
        if (left != right) return false;
        remainder = (remainder - left * (pow(10, inp_len - 1))) / 10;
        inp_len -= 2;
    }  

    return true;
}

int main(int argc, char** argv) {
    string inp_str = string(argv[1]);
    stringstream ss(inp_str);
    int inp_int;
    ss >> inp_int;
    cout << inp_int << endl;

    // cout << (soln1(argv[1]) ? "Is palindrome" : "Not palindrome") << endl;
    cout << (soln2(inp_int) ? "Is palindrome" : "Not palindrome") << endl;

    return 0;
}