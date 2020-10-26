//
//

#include <iostream>
#include "LinkedList.h"

void f() {
    LinkedList myLinkedList; // meg jo h kiirattuk es ellenoriztuk h lefut-e a destruktor...
    myLinkedList.addNode(5).addNode(10).addNode(12);
    myLinkedList.print();

    LifoList myLifoList; // meg jo h kiirattuk es ellenoriztuk h lefut-e a destruktor...
    myLifoList.addNode(5).addNode(10).addNode(12);
    myLifoList.print();
}

int main()
{
    char c;
    for (int i = 0; i < 10000; i++) {
        f();
        std::cin >> c;
    }
}
