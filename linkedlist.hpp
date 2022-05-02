#include <iostream>
#include "linkedlist.h"
using namespace std;

#ifndef LIST_HPP
#define LIST_HPP


ListNode::ListNode() {
    val = 0;
    next = nullptr;
}

ListNode::ListNode(int x) {
    val = x;
}

ListNode::ListNode(int x, ListNode *dest) {
    val = x;
    next = dest;
}

void ListNode::setNext(ListNode *dest) {
    next = dest;
}


List::List() {
    head = nullptr;
}

void List::insert(int val) {
    ListNode *tmp = new ListNode(val);
    tmp -> next = head;
    head = tmp;
    size ++;
}

void List::printList() {
    ListNode* curr = head;
    int count = size;
    while (count-- != 0) {
        cout << curr->val << endl;
        curr = curr -> next;
    }
}

void List::populate(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        insert(arr[i]);
    }
    cout << "done" << endl;
}

#endif