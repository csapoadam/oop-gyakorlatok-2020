#include <iostream>
#include <string>

#include "person.h"

Person::Person(std::string n, int a) {
    name = n;
    age = a > 0 ? a : 1;
    hairColor = "barna";
}

void Person::print() {
    std::cout << "Szia, egy ember vagyok. A nevem: ";
    std::cout << name << "... eletkorom: " << age;
    std::cout << ". A hajam szine: " << hairColor << std::endl;
}

Person& Person::setAge(int a) { // setter:
    // olyan metodus, mellyel jellemzoen privat tagvaltozok erteket
    // kontrollalt modon be lehet allitani
    age = a > 0 ? a : 1;
    return *this;
}

Person& Person::setHairColor(std::string hc) {
    hairColor = hc;
    return *this;
}

std::string& Person::getHairColor() {
    return hairColor;
}

int Person::getAge() { return age; }