//

#include <iostream>
#include "LinkedList.h"

int main()
{
    LifoList myLifoList;
    myLifoList.print();
    myLifoList.addNode(5).addNode(10).addNode(12);
    myLifoList.print();

    // TODO valahogy...
    LifoList myLifoList2(myLifoList);
    myLifoList2.print();

    myLifoList.addNode(15);
    myLifoList.print();
    myLifoList2.print();

    LinkedList myLinkedList;
    myLinkedList.print();
    myLinkedList.addNode(5).addNode(10).addNode(12);
    myLinkedList.print();

    std::cout << "----" << std::endl;
    LinkedList myLinkedList2(myLinkedList);
    myLinkedList2.print();
    myLinkedList.addNode(15);
    myLinkedList.print();
    myLinkedList2.print();

    myLinkedList2.addNode(17);
    myLinkedList.print();
    myLinkedList2.print();

    std::cout << "Toroljuk a myLinkedList2 elso elemet" << std::endl;
    myLinkedList2.deleteItem(1);
    myLinkedList2.print();

    std::cout << "Toroljuk az uj myLinkedList2 masodik elemet" << std::endl;
    myLinkedList2.deleteItem(2);
    myLinkedList2.print();
}
