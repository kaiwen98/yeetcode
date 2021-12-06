#include <iostream>
#include <map>
#include <vector>
/*
    Naive case 1
*/
int soln1(int arr[], size_t size_arr, int target);
int soln2(int arr[], size_t size_arr, int target);
int soln3(int arr[], size_t size_arr, int target);
std::vector<int> soln3_final(std::vector<int> &nums, int target);
void mergeSort(int arr[], int low, int high);
void merge(int a[], int low, int mid, int high);
int getIndexClosestElement(int arr[], int size, int target);
int binarySearch(int arr[], int low, int high, int target);

int main() {
    int arr[] = {2,7,11,15,20,21};
    int target = 22;

    std::vector<int> vec;

    for (int i = 0; i < 6; i++) {
        vec.push_back(arr[i]);
    } 


    size_t size_arr = sizeof(arr) / sizeof(int);

    for (auto i : soln3_final(vec, target)) {
        std::cout << i << "____" << std::endl;
    }
    return 0;
}

int soln1(int arr[], size_t size_arr, int target) {
    for (int i = 0; i < size_arr; i++) {
        for (int j = 0; j < size_arr; j++) {
            if (arr[i] + arr[j] == target) {
                std::cout << "Got " << arr[i] << " and " << arr[j] << std::endl; 
            }
        }
    }
    std::cout << "End scan" << std::endl;
    return 0;
}

int soln2(int arr[], size_t size_arr, int target) {
    int tmp[size_arr], tmp1[size_arr];
    mergeSort(arr, 0, (int)size_arr-1);
    for (int i = 0; i < size_arr; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // O(n)
    for (int i = 0; i < size_arr; i++) {
        tmp[i] = target - arr[i];
    }

    // O(nlogn)
    for (int i = 0; i < size_arr; i++) {
        tmp1[i] = binarySearch(arr, 0, size_arr-1, tmp[i]);
        if (tmp1[i] != -1) {
            std::cout << arr[i] << " -o-o-o- " << tmp[i] << std::endl;
        }
    }
    
    return 0;



    // Useless code that tests Binary Search that I suddenly feel like revising.
    // std::cout << "Index is " << getIndexClosestElement(arr, size_arr, target) << std::endl;
    // std::cout << "Index is " << binarySearch(arr, 0, (int)size_arr-1, target) << std::endl;


    return 0;
}

int soln3(int arr[], size_t size_arr, int target) {
    std::map<int, int> hmap;
    for (int i = 0; i < size_arr; i++) {
        auto key = hmap.find(arr[i]);
        if (key == hmap.end()) 
            // hmap.insert(std::pair<int, int>(target-arr[i], arr[i]));
            hmap[target-arr[i]] = arr[i];
        else 
            std::cout << key->first << "-o-o-o-" << key->second << std::endl;
    }
    return 0;
}

std::vector<int> soln3_final(std::vector<int> &nums, int target) {
    std::vector<int> ans;
    std::map<int, int> hmap;
    for (auto i : nums) {
        std::cout << i << std::endl;
        auto key = hmap.find(i);
        if (key == hmap.end()) {
            // std::cout << "lol";
            hmap[target-i] = i;
        }
        else  {
            ans.push_back(key->first);
            ans.push_back(key->second);
            // std::cout << key->first << "-o-o-o-" << key->second << std::endl;
            return ans;
        }
    }
    return ans;
}



/*
    Binary Search
*/

int getIndexClosestElement(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int mid = 0;
    int size_c = high - low;
    while (high - low >= 1) {
        mid = (high + low) / 2;
        std::cout << low << "---" << mid << "---" << high << "---" << target << std::endl; 
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[low] == target) {
            return low;
        } else if (arr[high] == target) {
            return high;
        }
        if (arr[mid] > target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

        if (size_c == high - low) {
            std::cout << "Fail" << std::endl;
            return 0;
        } else {
            size_c = high - low;
        }
    }
    mid = (high + low) / 2;
    std::cout << low << "---" << mid << "---" << high << "---" << target << std::endl; 
    return mid;
}

int binarySearch(int arr[], int low, int high, int target) {
    int mid = (low + high) /2;
    std::cout << low << "---" << mid << "---" << high << "---" << target << std::endl; 
    if (arr[mid] == target) {
        return mid;
    } 

    if (low > high) {
        // int temp = high;
        // high = low;
        // low = temp;
        // if (target > arr[low]) return low;
        // else if (target < arr[high]) return high;
        // else {
        //     return (abs(arr[low] - target) > abs(arr[high] - target)) ? high : low;
        // }
        return -1;
    }

    if (arr[mid] < target) return binarySearch(arr, low, mid-1, target);
    return binarySearch(arr, mid+1, high, target);
}


/*
    Divide and conquer
*/
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

/*
    l      r
    00000001111111

    01001010110111

    Idea is that the unit cases and upwards are properly sorted.
*/

void merge(int a[], int low, int mid, int high) {
    int size = high - low + 1;
    int b[size];
    int left = low; 
    int right = mid + 1;
    int bIdx = 0;
    while (left <= mid && right <= high) {
        b[bIdx++] = (a[left] >= a[right]) ? a[left++] : a[right++];
    }
    while (left <= mid) b[bIdx++] = a[left++];
    while (right <= high) b[bIdx++] = a[right++];
    for (int k = 0; k < size; k++) a[low+k] = b[k];
}