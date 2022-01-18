#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int rec = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i] + rec) {
                rec = nums[i];
            } else {
                rec = nums[i] + rec;
            }

            max = rec > max ? rec : max;
        }

        return max;
    }
};

int main() {
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> vec(
        begin(arr),
        end(arr)
    );
    Solution soln;
    
    for (int i : vec) {
        cout << i << " ";
    } cout << endl;

    cout << soln.maxSubArray(vec) << endl;
    

    // for (int i : vec) {
    //     cout << i << " ";
    // } cout << endl;
    
}