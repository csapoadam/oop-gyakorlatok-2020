// Valasztas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "registry.h"

void f() {
    ValasztasiJegyzek vj; // VotingRegistry

    vj.addVoter(new Voter("Paul Szabo", "New York City", 41, 103410));
    vj.addVoter(new Voter("Aaron Rosenfeldt", "Syracuse", 32, 444512));
    vj.addVoter(new Voter("Sarah Smith", "Buffalo", 24, 471832));
    vj.addVoter(new Voter("Carla Boyce", "Rochester", 22, 471832));
    vj.printVoters();
}

int main()
{
    char c;
    for (int i = 0; i < 10; i++) {
        f(); // ha f kilep, a mem.nek fel kell szabadulnia!
        std::cin >> c; // heap profiling celjabol!
    }
}
