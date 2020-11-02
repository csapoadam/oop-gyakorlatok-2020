//
//

#include <iostream>
#include <vector>
#include "LinkedList.h"

void addNodesThenPrint(DynamicList* dynamicList, std::vector<int> intvec) {
    for (int elem : intvec) {
        dynamicList->addNode(elem);
    }
    dynamicList->print();
}

void printDynamicLists(std::vector<DynamicList*> dlvec) {
    for (DynamicList* dl : dlvec) {
        dl->print();
    }
}

void f() {
    LifoList myLifoList; // meg jo h kiirattuk es ellenoriztuk h lefut-e a destruktor...
    addNodesThenPrint(&myLifoList, std::vector<int>{5, 10, 12});

    LifoList myLifoList2;
    addNodesThenPrint(&myLifoList2, std::vector<int>{15, 16});

    myLifoList2 = myLifoList;
    LifoList myLifoList3(myLifoList);

    myLifoList2.addNode(17);
    myLifoList3.addNode(18);

    std::cout << "A harom lancolt lifo lista:" << std::endl;
    printDynamicLists(std::vector<DynamicList*>{&myLifoList, &myLifoList2, &myLifoList3});
}

void g() {

    FifoList myFifoList; // meg jo h kiirattuk es ellenoriztuk h lefut-e a destruktor...
    addNodesThenPrint(&myFifoList, std::vector<int>{5, 10, 12});

    FifoList myFifoList2;
    addNodesThenPrint(&myFifoList2, std::vector<int>{15, 16});

    myFifoList2 = myFifoList;
    FifoList myFifoList3(myFifoList);

    myFifoList2.addNode(17);
    myFifoList3.addNode(18);
    
    std::cout << "A harom lancolt fifo lista:" << std::endl;
    printDynamicLists(std::vector<DynamicList*>{&myFifoList, & myFifoList2, & myFifoList3});    
}

int main()
{
    char c;
    for (int i = 0; i < 10000; i++) {
        f();
        g();
        std::cin >> c;
    }
}