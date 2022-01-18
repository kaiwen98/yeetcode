#pragma once

#include <iostream>

template <class T>
class LinkedList;

template <class T>
class ListNode {
    public:
        ListNode(T inpValue) {
            value = inpValue;
            next = nullptr;
        }

        ListNode* getNextNode();
        T& peekValue();

    private:
        friend class LinkedList<T>;
        T value;
        ListNode *next;
        
};

template <class T>
class LinkedList {
    public:
        ListNode<T> *head;
        int size;

        LinkedList() { 
            size = 0;
            head = nullptr; 
        }

        T& operator[](int);

        template <class S>
        friend std::ostream& operator<<(std::ostream& os, const LinkedList<S> &ls);

        int addFront(T);

        int addBack(T);

        int addAt(T, int);

        int popFront();

        int popBack();

        bool removeAtIndex(int);

        bool replaceAtIndex(int, T);

        void printList();

        ~LinkedList() ;
        
    private:
        
};

#include "LinkedList.hpp"
