// Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "library.h"

void magazineAdded(Magazine* m) {
    std::cout << "Magazine added to library: " << std::endl;
    m->print();
}

void magazineAddedStartsWithT(Magazine* m) {
    if (m->getTitle().length() > 0 && m->getTitle().substr(0, 1).compare("T") == 0) {
        std::cout << "Magazine added whose title starts with a letter T!" << std::endl;
    }
}

void kiszervezettFv() {
    Library mylib;
    // function pointereknek nezzenek utana!
    mylib.addMagazineEventHandler(magazineAdded); // event handler hozzaadasa. minden magazine hozzadasakor meghivodik
    mylib.addMagazineEventHandler(magazineAddedStartsWithT); // T-vel kezdodo magazinok hozzadasakor meghivodik

    Publication* book1 = new Book("A Slap in the Face", "William B. Irvine"); // cim, szerzo
    Publication* magazine1 = new Magazine("T-Mag", 2020, 1); // evfolyam, szam
    Publication* book2 = new Book("Running to the Edge", "Matthew Futterman");
    Publication* magazine2 = new Magazine("Codemag", 2020, 6);

    mylib.addPublication(book1);
    mylib.addPublication(magazine1); // itt kiirja, hogy:
    // Magazine added to library :
    // "T-Mag", vol. 2020, no. 1
    // Magazine added whose title starts with a letter T!
    mylib.addPublication(book2);
    mylib.addPublication(magazine2); // itt kiirja, hogy:
    // Magazine added to library:
    // "Codemag", vol. 2020, no. 6

    mylib.print(); // kiirja, hogy:
    // ====
    // Contents of library :
    // "A Slap in the Face" by William B.Irvine
    // "Running to the Edge" by Matthew Futterman
    // "Codemag", vol. 2020, no. 6
}

int main()
{
    char c;
    for (int i = 0; i < 10; i++) {
        kiszervezettFv();
        std::cin >> c; // itt nezzunk mindig heap snapshotot - mindig ugyanannyi mem. legyen lefoglalva!
    }
}
