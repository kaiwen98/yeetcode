#include "LinkedList/LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    // LinkedList<int> *ls = new LinkedList<int>();
    // ls -> addFront(6);
    // ls -> addFront(5);
    // ls -> addFront(4);
    // ls -> addFront(3);
    // ls -> addFront(2);
    // ls -> addFront(1);
    // ls -> addBack(8);
    // ls -> printList();
    LinkedList<int> ls;
    ls.addFront(6);
    ls.addFront(5);
    ls.addFront(4);
    ls.addFront(3);
    ls.addFront(2);
    ls.addFront(1);
    ls.addBack(8);
    ls.printList();
    cout << ls;

    cout << ls[3] << endl;
    // cout << ls -> test() << endl;
    // delete ls;
    return 0;
}