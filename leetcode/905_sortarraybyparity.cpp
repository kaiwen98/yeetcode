#include <iostream>
#include <vector>
/*
    1 5 2 1 8 2 6 3
    ^ ^       ^ ^
*/
class Solution {
public:
    // Maintains two pointers that swaps iteratively
    std::vector<int> sortArrayByParity1(std::vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        std::vector<int> output = nums;
        std::vector<int>::iterator beg = output.begin(), curr_beg = beg, end = output.end() - 1, curr_end = end;
        int incre = 0, decre = 0;
        while (true) {
            while (*curr_beg % 2 == 0 && (++incre < nums.size() - 1)) curr_beg++; 
            while (*curr_end % 2 && (++decre < nums.size() - 1)) curr_end--; 
            if ((incre + decre) >= nums.size() - 1) break;
            (*curr_beg ^= *curr_end), (*curr_end ^= *curr_beg), (*curr_beg ^= *curr_end);
        }
        return output;
    }

    // Shorter version
    std::vector<int> sortArrayByParity2(std::vector<int>& nums) {
        int max = nums.size() - 1;
        int l = 0, r = max;
        do {
            if (l + r != 0) nums[l] ^= nums[r], nums[r] ^= nums[l], nums[l] ^= nums[r];
            while (!(nums[l] % 2) && l < max) l++;
            while (nums[r] % 2 && r > 0) r--;
        } while (l < r);
        return nums;
    }
};

int main() {
    Solution soln;
    std::vector<int> input{0, 1, 2, 3, 4}, output;
    output = soln.sortArrayByParity2(input);
    for (auto &i : output) {
        std::cout << i << " ";
    }
    return 0;
}