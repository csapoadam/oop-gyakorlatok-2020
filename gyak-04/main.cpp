//
//

#include <iostream>
#include "LinkedList.h"

void f() {
    LifoList myLifoList; // meg jo h kiirattuk es ellenoriztuk h lefut-e a destruktor...
    myLifoList.addNode(5).addNode(10).addNode(12);
    myLifoList.print();

    LifoList myLifoList2;
    myLifoList2.addNode(15).addNode(16);
    myLifoList2.print();

    myLifoList2 = myLifoList;
    myLifoList2.addNode(17);
    std::cout << "A ket lancolt lifo lista:" << std::endl;
    myLifoList.print();
    myLifoList2.print();
}

void g() {

    FifoList myFifoList; // meg jo h kiirattuk es ellenoriztuk h lefut-e a destruktor...
    myFifoList.addNode(5).addNode(10).addNode(12);
    myFifoList.print();

    FifoList myFifoList2;
    myFifoList2.addNode(15).addNode(16);
    myFifoList2.print();

    myFifoList2 = myFifoList;
    myFifoList2.addNode(17);
    std::cout << "A ket lancolt fifo lista:" << std::endl;
    myFifoList.print();
    myFifoList2.print();
}

int main()
{
    char c;
    for (int i = 0; i < 10000; i++) {
        g();
        std::cin >> c;
    }
}