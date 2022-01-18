#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
        int prev;
        int removed = 0;
        int size = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            prev = nums[i-1];

            cout << "prev " << prev << endl;
            cout << "curr " << nums[i] << endl;
            
            if (prev == nums[i]) {
                nums.erase(nums.begin() + i);
                removed++;
                i--;
            } 
        }
        return size - removed;
    }

    int removeDuplicates(vector<int>& nums) {
        set<int> s(
            nums.begin(),
            nums.end()
        );

        nums.clear();

        nums.assign(
            s.begin(),
            s.end()
        );

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

    cout << soln.removeDuplicates(vec) << endl;
    

    for (int i : vec) {
        cout << i << " ";
    } cout << endl;
    
}