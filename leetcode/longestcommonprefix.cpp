#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            char output[1000] = "";
            bool is_same;
            int max_char = 0;
            for (int i = 0; i < strs[0].length(); i++) {
                is_same = true;
                for (auto s : strs) {
                    if (s[i] != strs[0][i]) {
                        is_same = false;
                        break;
                    }
                }
                if (is_same) {
                    max_char += 1;
                }
                else 
                    break;
            }
            return strs[0].substr(0, max_char);
        }

        string longestCommonPrefix1(vector<string>& strs) {
            int max_char = 0;
            while(1) {
                for (auto &s : strs) {
                    if (s.size() < max_char || s[max_char] != strs[0][max_char]) {
                        return strs[0].substr(0, max_char);
                    }
                }
                max_char++;
            }
            return strs[0].substr(0, max_char);
        }
};

int main() {
    Solution solution;
    vector<string> test_case{
        "strfing",
        "strfung",
        "strfong"
    };
    cout << solution.longestCommonPrefix1(test_case) << endl;
}