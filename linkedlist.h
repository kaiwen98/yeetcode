#include <iostream>
using namespace std;

#pragma once

class ListNode {
    public:
        ListNode *next = nullptr;
        int val;
        ListNode() ;

        ListNode(int x) ;
        ListNode(int x, ListNode *dest) ;

        void setNext(ListNode *dest) ;
        
    private:
};

class List {
    public:
        ListNode *head;
        int size = 0;
        List() ;
        void insert(int val) ;

        void printList() ;

        void populate(int arr[], int size) ;
};

#include "linkedlist.hpp"