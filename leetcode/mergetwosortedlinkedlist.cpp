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

class ListNode {
    public:
        ListNode *next = nullptr;
        int val;

        ListNode(int x, ListNode *dest) {
            val = x;
            cout << val << endl;
            next = dest;
        }

        ListNode(int x) {
            val = x;
        }

        ListNode() {
            val = 0;
        }

        void setNext(ListNode *dest) {
            next = dest;
        }
    
    private:
};

class List {
    public:
        ListNode *head;
        int size = 0;

        List() {
            head = nullptr;
        }

        void insert(int val, bool isReverse = false) {
            if (head == nullptr) {
                head = new ListNode(val);
            } else if (isReverse){
                ListNode *tmp = new ListNode(val);
                tmp -> next = head;
                head = tmp;
            } else {
                ListNode *tmp = new ListNode(val);
                ListNode *tail = head;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }
                tail -> next = tmp;
            }
        }

        void printList() {
            ListNode* curr = head;
            cout << curr->val << " ";
            while (curr->next != nullptr) {
                curr = curr->next;
                cout << curr->val << " ";
            }
            cout << endl;
        }

        void populate(int arr[], int size, bool isReverse = false) {
            for (int i = 0; i < size; i++) {
                insert(arr[i], isReverse);
            }
        }
};

void printList(ListNode* ls) {
    ListNode* curr = ls;
    cout << curr->val << " ";
    while (curr->next != nullptr) {
        curr = curr->next;
        cout << curr->val << " ";
    }
    cout << endl;
}

class Solution {
public:
/*
5 3 1 

6 4 2



*/
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* prev = nullptr;
        ListNode* sec = list2;
        ListNode* temp = new ListNode();
        ListNode* ans = list1;
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        while(curr != nullptr && sec != nullptr) {

            cout << "curr: " << curr->val << endl;
            if (prev != nullptr)
                cout << "prev: " << prev->val << endl;

            if (curr->val < sec->val) {
                temp = sec -> next;
                sec -> next = curr;
                if (prev != nullptr) {
                    prev -> next = sec;
                } else {
                    ans = sec;
                }
                prev = sec;
                sec = temp;

            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        while (sec != nullptr) {
            cout << prev->val << endl;
            prev -> next = sec;
            sec = sec->next;
            prev = prev->next;
        }
        return ans;
    }

};

int main() {
    Solution solution;
    List *list1 = new List();
    List *list2 = new List();
    int arr1[] = {};
    int arr2[] = {0};
    cout << "hi" << endl;
    list1 -> populate(arr1, 1, true);
    list2 -> populate(arr2, 1, true);
    list1->printList();
    list2->printList();
    printList(solution.mergeTwoLists(list1->head, list2->head));
}