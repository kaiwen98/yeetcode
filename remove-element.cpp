#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums, int val) {
        vector<int> ans = nums;
        nums.clear();
        copy_if (ans.begin(), ans.end(), std::back_inserter(nums), [val](int i){return i!=val;} );
        return nums.size();
    }

    int removeDuplicates1(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(
                    nums.begin()+i
                );
                i--;
            }
        }
        return nums.size();
    }
};

int main() {
    int arr[] = {1, 2, 2, 3, 4, 5};
    vector<int> vec(
        begin(arr),
        end(arr)
    );
    Solution soln;
    
    for (int i : vec) {
        cout << i << " ";
    } cout << endl;

    cout << soln.removeDuplicates(vec, 2) << endl;
    

    for (int i : vec) {
        cout << i << " ";
    } cout << endl;
    
}