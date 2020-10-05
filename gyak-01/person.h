#pragma once

class Person {
private:
    std::string name;
    std::string hairColor;
    int age;
public:
    //Person() { // alapertelmezett konstruktor
    //    // mindig ez hivodik meg, ha argumentum nelkul peldanyositjuk
    //    name = "Bela";
    //}
    Person(std::string, int);
    void print();
    Person& setAge(int);
    Person& setHairColor(std::string);
    std::string& getHairColor();
    int getAge();
};