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
using namespace std;

class List {
    public:
        ListNode *head;
        int size = 0;
        List() {
            head = nullptr;
        }

        void insert(int val) {
            ListNode *tmp = new ListNode(val);
            tmp -> next = head;
            head = tmp;
        }

        void printList() {
            ListNode* curr = head;
            cout << curr->val << endl;
            if (next != nullptr) {
                next -> printList();
            }
        }

        ListNode* populate(int arr[], int size) {
            head = new ListNode(arr[0]);
            ListNode *curr = head;

            for (int i = 1; i < size; i++) {

                
                curr = curr->next;
                curr = new ListNode(arr[i]);
                // cout << "sadad" << arr[i] << endl;
                // cout << head -> val << endl;
                
            }
            cout << head -> next -> val << endl;
            cout << "done" << endl;
            return head;
        }
};

class ListNode {
    public:
        ListNode *next = nullptr;
        int val;
        ListNode() {
            val = 0;
            next = nullptr;
        }

        ListNode(int x) {
            val = x;
        }

        ListNode(int x, ListNode *dest) {
            val = x;
            next = dest;
        }

        void setNext(ListNode *dest) {
            next = dest;
        }
        



    private:
        
        

};




class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return nullptr;
    }
};

int main() {
    Solution solution;
    List *list1;
    int arr[] = {1, 2, 3, 4, 5};
    cout << list1->val << endl;
    list1 -> printList();
    cout << solution.mergeTwoLists(list1, list1) << endl;
}