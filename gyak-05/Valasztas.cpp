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
    vj.printVoters();

    Election election2020("Valasztas-2020", 3); // jeloltek szama
    vj.initializeElection(election2020);

    // ezutan valami ilyesmi lesz:
    vj.vote(471832, election2020, 1); // adott id-ju szavazo adott valasztason adott jeloltre szavaz
    vj.vote(999999, election2020, 2); // ilyen id-ju szavazo nincs!!
    vj.vote(471832, election2020, 1); // 2x nem lehet szavazni!!

    //election2020.printResults();
}

int main()
{
    char c;
    for (int i = 0; i < 10; i++) {
        f(); // ha f kilep, a mem.nek fel kell szabadulnia!
        std::cin >> c; // heap profiling celjabol!
    }
}
