// Valasztas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "registry.h" // ez a header meg include-olja az election.h-t is

void f() {
    ValasztasiJegyzek vj; // VotingRegistry

    vj.addVoter(new Voter("Paul Szabo", "New York City", 41, 103410));
    vj.addVoter(new Voter("Aaron Rosenfeldt", "Syracuse", 32, 444512));
    vj.addVoter(new Voter("Sarah Smith", "Buffalo", 24, 471832));
    vj.addVoter(new Voter("Carla Boyce", "Rochester", 22, 471832));
    //vj.printVoters();

    Election election2020("Valasztas-2020", 3); // jeloltek szama
    vj.initializeElection(election2020);

    vj.printVoters();

    // ezutan valami ilyesmi lesz:
    //psz->vote(&election2020, 1); // szavazott az 1. jeloltre
    //ssm->vote(&election2020, 2); // szavazott a 2. jeloltre
}

int main()
{
    char c;
    for (int i = 0; i < 10; i++) {
        f(); // ha f kilep, a mem.nek fel kell szabadulnia!
        std::cin >> c; // heap profiling celjabol!
    }
}
