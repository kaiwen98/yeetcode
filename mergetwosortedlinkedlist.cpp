/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include "linkedlist.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return nullptr;
    }
};

int main() {
    Solution solution;
    List *list1 = new List();
    int arr[] = {1, 2, 3, 4, 5};
    list1 -> populate(arr, sizeof(arr)/sizeof(int));
    list1 -> printList();
    cout << solution.mergeTwoLists(list1->head, list1->head) << endl;
}