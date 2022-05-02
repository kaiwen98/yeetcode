#include <iostream>
#include <vector>
/*

1 5 2 1 8 2 6 3



*/

void swap(std::vector<int>::iterator a, std::vector<int>::iterator b) {
    std::cout << "a is " << *a;
    std::cout << "\nb is " << *b;
    (*a ^= *b), (*b ^= *a), (*a ^= *b);
    std::cout << "\na now is " << *a << std::endl; 
    std::cout << "b now is " << *b << std::endl; 
}

bool is_odd(int a) { return a % 2; } 

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        std::vector<int> output = nums;
        std::vector<int>::iterator beg = output.begin(), curr_beg = beg;
        std::vector<int>::iterator end = output.end() - 1, curr_end = end;
        int incre = 0, decre = 0;
        while (true) {
            while (
                (!is_odd(*curr_beg)) && (incre < nums.size() - 1)
            ) { 
                incre++; 
                curr_beg = beg + incre; 
            }
            while (
                (is_odd(*curr_end)) && (decre < nums.size() - 1)
            ) { 
                decre++; 
                curr_end = end - decre; 
            }
            if (decre == nums.size() || incre == nums.size()) break;
            if ((incre + decre) >= nums.size() - 1) break;
            swap(curr_beg, curr_end);
        }

        return output;
    }
};

int main() {
    Solution soln;
    std::vector<int> input{1, 5, 0, 2, 3}, output;
    std::cout << input.size() << std::endl;
    output = soln.sortArrayByParity(input);
    for (auto &i : output) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}