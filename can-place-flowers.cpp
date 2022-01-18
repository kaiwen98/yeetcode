#include <iostream>
#include <vector>
#include <string>
using namespace std;

int arr[] = {1,0,0,0,0,1};

class Solution {
public:
    bool canPlaceFlowers1(vector<int>& flowerbed, int n) {
        bool leftOkay, rightOkay;
        int count = n;
        for (int i = 0; i < flowerbed.size() && count != 0; i++) {
            if (flowerbed[i] == 1) continue;

            if (i - 1 >= 0) {
                leftOkay = *(flowerbed.begin() + i - 1) == 0;
            } else leftOkay = true;

            if ((i + 1) < flowerbed.size()) {
                rightOkay = *(flowerbed.begin() + i + 1) == 0;
            } else rightOkay = true;

            if (leftOkay && rightOkay) {
                flowerbed[i] = 1;
                count--;
            } 
        }

        return count == 0;
    }

    bool canPlaceFlowers2(vector<int>& flowerbed, int n) {
        int count = n;
        std::string str(flowerbed.begin(), flowerbed.end());
        cout << str << endl;
        return count == 0;
    }
};

int main() {
    Solution solution;
    vector<int> vec(begin(arr), end(arr));
    cout << solution.canPlaceFlowers2(vec, 2) << endl;
}