#include "LinkedList.h"
#include <iostream>
#include "../Exception/exception.h"

using namespace std;

template <class T>
void LinkedList<T>::printList() {
    int count = size;
    ListNode<T>* currNode = head;

    while (currNode != nullptr) {
        if (count == 1 || count == size) {
            cout << ( count == size ? "(head) " : " - (tail) " ) << currNode -> value;
        } else {
            cout << " - " << currNode -> value; 
        }
        currNode = currNode -> next;
        count --;
    }

    cout << endl;
}

template <class T>
T& LinkedList<T>::operator[](int index) {
    ListNode<T> *currNode = head;
    int count = 0;
    if (index < 0 || index > size - 1) {
        throw OutOfRangeException();
    }

    while(count++ < index ) {
        currNode = currNode -> next;
    }

    return currNode -> value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T> &ls) {
            int count = ls.size;
            ListNode<T>* currNode = ls.head;

            while (currNode != nullptr) {
                if (count == 1 || count == ls.size) {
                    os << ( count == ls.size ? "(head) " : " - (tail) " ) << currNode -> peekValue();
                } else {
                    os << " - " << currNode -> peekValue(); 
                }
                currNode = currNode -> getNextNode();
                count --;
            }

            os << std::endl;
            return os;
        }

template <class T>
int LinkedList<T>::addFront(T input) {
    ListNode<T>* newNode = new ListNode<T>(input);
    newNode->next = head;
    head = newNode;
    return size++;
}

template <class T>
int LinkedList<T>::addBack(T input) {
    ListNode<T>* currNode = head;
    ListNode<T>* newNode = new ListNode<T>(input);
    if (head == nullptr) {
        head = newNode;
    } else {
        while (currNode -> next != nullptr) {
            currNode = currNode -> next;
        }
        
        currNode -> next = newNode;
    }
    return size++;
}

template <class T>
int LinkedList<T>::addAt(T input, int index) {
    ListNode<T> currNode = head;
    ListNode<T> newNode = new ListNode(input);
    int count = 0;
    if (index < size - 1) {
        throw OutOfRangeException;
    }

    while ( count++ < index ) {
        currNode = currNode -> next;
    }

    newNode -> next = currNode -> next;
    currNode -> next = newNode;
    return size++;
}

template <class T>
int LinkedList<T>::popFront() {

}

template <class T>
int LinkedList<T>::popBack() {
    
}

template <class T>
LinkedList<T>::~LinkedList() {
    int count = size;
    ListNode<T>* currNode = head;
    ListNode<T>* nextNode = currNode;

    cout << "Deletion called!" << endl;
    while (currNode != nullptr) {
        nextNode = currNode -> next;
        delete currNode;
        currNode = nextNode;
        size --;
    }
}

template <class T>
T& ListNode<T>::peekValue() {
    return value;
}

template <class T>
ListNode<T>* ListNode<T>::getNextNode() {
    return next;
}
