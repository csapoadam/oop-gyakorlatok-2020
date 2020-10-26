//
//

#include <iostream>
#include "LinkedList.h"

void f() {
    LinkedList myLinkedList; // meg jo h kiirattuk es ellenoriztuk h lefut-e a destruktor...
    myLinkedList.addNode(5).addNode(10).addNode(12);
    myLinkedList.print();

    LinkedList myLinkedList2;
    myLinkedList2.addNode(15).addNode(16);
    myLinkedList2.print();

    myLinkedList2 = myLinkedList;
    myLinkedList2.addNode(17);
    std::cout << "A ket lancolt lista:" << std::endl;
    myLinkedList.print();
    myLinkedList2.print();
}

int main()
{
    char c;
    for (int i = 0; i < 10000; i++) {
        f();
        std::cin >> c;
    }
}
