#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"

int main() {
    SinglyLinkedList<int> sList;

    sList.push_back(10);
    sList.push_front(5);
    sList.push_back(20);

    sList.print();

    sList.remove(1);
    sList.print();

    DoublyLinkedList<int> dList;

    dList.push_back(1);
    dList.push_back(2);
    dList.push_front(0);

    dList.print();

    return 0;
}