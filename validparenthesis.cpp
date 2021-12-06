#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            char tmp;
            vector<char> stack;
            map<char, char> map {
                {'}', '{'},
                {']', '['},
                {')', '('}
            };
            for (auto c : s) {
                if (c == '[' || c == '{' || c== '(') {
                    stack.push_back(c);
                } else {
                    try {
                        tmp = map.at(c);
                        if (stack.size() > 0 && tmp == stack.back()) {
                            stack.pop_back();
                        } else {
                            return false;
                        }
                    } catch (out_of_range& oor) {
                        continue;
                    }
                }
            }
            return stack.size() == 0;
        }
};

int main() {
    Solution solution;
    string test_case = "[a]";
    cout << solution.isValid(test_case) << endl;
}