// ConsoleApplication17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "person.h"
#include "date.h"

int main()
{
    // std::cout << "Hello World!\n";

    Date d{ "kezdetben 2020. oktober 5", 2020, 10, 5 };
    d.addDays(15);
    d.print();

    d.addDays(25).print();
    d.addDays(60).print();
    d.addDays(60).print();

    const Date constd{ "konstans datum", 2020, 10, 12 };
    constd.print();

    try {
        Date d2{ "", 2020, 15, 3 };
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Date d3{ "", 2020, 11, 31 };
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Date d4{ "", 2021, 2, 29 };
        d4.print();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    /*
    Person p("Bela", -36);
    //p.age = 15;
    p.setAge(35).setHairColor("lila").print();

    std::cout << "Hi, my name is Bela. I am " << p.getAge() << "years old." << std::endl;

    Person p5("Dalma", 26);
    Person& p6 = p5.setAge(28).setHairColor("szoke");
    std::cout << p5.getAge() << std::endl;
    std::cout << p5.getHairColor() << std::endl;
    std::cout << p6.getAge() << std::endl;
    std::cout << p6.getHairColor() << std::endl;

    p6.setAge(30);
    std::cout << p5.getAge() << std::endl;


    std::cout << "---" << std::endl;

    //p.name = "Balint";
    Person p1 = Person("Anna", 21);
    Person p2 = Person{"Petra", 18}; // jobb, mert nincs implicit szukites
    Person* p3 = new Person{"Peter", 26};

    //int a = 560000;
    //char b{ a }; // ez a sor nem fordulna le! implicit narrowing
    //char b(a); // ez persze lefordul
    //std::cout << b << std::endl;


    //p.print();
    p1.print();
    p2.print();
    p3->print();

    delete p3;

    */

    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
