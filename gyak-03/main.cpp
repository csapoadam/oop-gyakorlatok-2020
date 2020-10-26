//
//

#include <iostream>
#include "LinkedList.h"

void f() {
    LifoList myLifoList;
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
