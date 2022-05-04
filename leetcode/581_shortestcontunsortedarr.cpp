#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;
/*
   Very slow solution despite the use of quicksort and radixsort...
   */

void print_vector(vector<int> &input) {
    cout << "arr: ";
    for (int i : input) {
        cout << i << " ";
    }
    cout << endl;
}

int extract_digit_at_place(int input, int place) {
    int sub = (input/(pow(10, place))); 
    return (input - sub * pow(10, place)) / pow(10, place - 1); 
}

int extract_digit_at_place_with_order(int input, int place, bool asc) {
    int val = extract_digit_at_place(input, place);  
    return !asc ? 9 - val : val;
}

vector<int> countingSort(vector<int> &input, int place, bool asc) {
    vector<int> buf(10);
    vector<int> output = input;

    //print_vector(input);
    for (int i : input) {
        buf[extract_digit_at_place_with_order(i, place, asc)]++;
    }
    //print_vector(buf);

    for (int i = 0; i < buf.size() - 1; i++) {
        buf[i+1] += buf[i];
    }

    //print_vector(buf);
    for (int i = input.size() - 1; i >= 0; i--) {
        output[buf[extract_digit_at_place_with_order(input[i], place, asc)] - 1] = input[i];
        buf[extract_digit_at_place_with_order(input[i], place, asc)]--;
    }
    return output;
}

vector<int> radixSort(vector<int> &input, bool asc, bool is_neg) {
    vector<int> output = input;
    int max = 0; 
    int num_digits = 0;
    for (int i = 0; i < input.size(); i++) {
        if (is_neg) output[i] *= -1;
        max = output[i] > max ? output[i] : max;
    }
    while ((int)(max / pow(10, num_digits)) > 0) num_digits++;
    for (int i = 1; i <= num_digits; i++) {
        output = countingSort(output, i, asc);
    } 
    for (int i = 0; i < input.size(); i++) {
        if (is_neg) output[i] *= -1;
    }
    return output;
}

vector<int> sortArr(vector<int> &input) {
    int j = 0;
    vector<int> temp = input;
    int tmp;
    for (int k = 0; k < temp.size(); k++) {
        if (temp[k] < 0) {
            tmp = temp[j];
            temp[j] = temp[k];
            temp[k] = tmp;
            j++;
        }
    }
    vector<int> l_vec = {temp.begin(), temp.begin()+j};
    vector<int> r_vec = {temp.begin()+j, temp.end()};
    l_vec = radixSort(l_vec, false, true);
    r_vec = radixSort(r_vec, true, false);
    l_vec.insert(l_vec.end(), r_vec.begin(), r_vec.end());
    return l_vec;
}

class Solution {
    public:
        int findUnsortedSubarray(std::vector<int>& nums) {
            print_vector(nums);
            int front = 0, back = 0, last_index = nums.size() - 1;
            vector<int> sortedArr = sortArr(nums);
            print_vector(nums);
            print_vector(sortedArr);
            cout << last_index << endl;
            while (front <= last_index && sortedArr[front] == nums[front]) front++;
            while (back <= last_index && front != last_index + 1 && sortedArr[last_index - back] == nums[last_index - back]) back++;
            cout << front << " vs " << back << endl;
            int output = nums.size() - (front + back);
            return output;
        } 
        
        // Turns out you don't need to sort the entire array, just take max and min
        int findUnsortedSubarray1(std::vector<int>& nums) {
            int max = 0;
            int min = INT_MAX;

            for (int i : nums) {
                max = i > max ? i : max;
                min = i < min ? i : min;
            }

            int last_index = nums.size() - 1;
            int curr = min;
            int forward = 0, backward = 0;
            cout << "last " << last_index << endl;
            if (nums[forward] == min) {
                while(1) {
                    forward++;
                    if (forward > last_index || curr > nums[forward]) break;
                    else curr = nums[forward];
                }
            }
            cout << "for " << forward << endl; 
            curr = max;
            if (forward < last_index + 1 && nums[last_index - backward] == max) {
                while(1) {
                    backward++;
                    if (backward > last_index || curr < nums[last_index - backward]) break;
                    else curr = nums[last_index - backward];
                }
            }
            cout << "bac " << backward << endl;
            cout << max << " vs " << min << endl;
            cout << forward << " vs " << backward << endl; 
            return last_index + 1 - forward - backward;
        }
};

int main() {
    Solution soln;
    std::vector<int> input{-100, -99, -92, 73, 4, 20, 63, 700};
    //`std::vector<int> input{1, 2, 3, 4};
 
    int output;
    output = soln.findUnsortedSubarray1(input);
    cout << output << endl;
    return 0;
}
