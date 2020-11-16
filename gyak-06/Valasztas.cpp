// Valasztas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cassert>
#include <iostream>
#include "registry.h"

void f() {
    Registry reg; // VotingRegistry

    reg.addVoter("Paul Szabo", "New York City", 41, 103410); // nev, varos, eletkor, egyedi id
    reg.addVoter("Aaron Rosenfeldt", "Syracuse", 32, 444512);
    reg.addVoter("Sarah Smith", "Buffalo", 24, 471832);
    reg.addVoter("Latonya Cooper", "Yonkers", 22, 314564);
    reg.addVoter("Michael Dodds", "Elmira", 76, 216997);
    reg.addVoter("Carla Boyce", "Rochester", 22, 471832); // hupsz ilyen id mar van
    // kiirja hogy:
    //  ---> could not add voter: 471832: Carla Boyce -- 22 yrs old -- Rochester
    // because voter by name Sarah Smith has the same id!
    reg.printVoters(); // kiirja, az osszes regisztralt szavazot:


    Election election2020("Valasztas-2020", 3, reg); // jeloltek szama, registry

    // ugyeljunk arra, hogy se Ballot, se InPersonBallot, se MailInBallot osztalyok
    // ne legyenek itt peldanyosithatoak - regen rossz lenne ha a valasztast
    // meg lehetne hackelni!
    // Ballot ballot0(election2020); // nem mukodik, absztrakt ososztaly!
    // InPersonBallot ballot0(election2020); // nem absztrakt osztaly de megsem mukodik (pedig van ilyen konstruktor)!
    // MailInBallot ballot0(election2020, 471832); // szinten nem mukodik (pedig van ilyen konstruktor)!

    Ballot* ballot1 = election2020.getMailInBallot(103410); // ha az id benne van a registry-ben kiadjuk
    Ballot* ballot2 = election2020.getMailInBallot(103410); // akar masodszor is
    
    Ballot* ballot3 = election2020.getInPersonBallot(444512); // ha az id benne van a registry-ben kiadjuk
    Ballot* ballot4 = election2020.getInPersonBallot(444512); // de masodszor nullptr-t adunk vissza
    assert(ballot4 == nullptr); // nullptr kell hogy legyen! mert mar szavazott szemelyesen

    Ballot* ballot5 = election2020.getMailInBallot(314564);
    Ballot* ballot6 = election2020.getInPersonBallot(314564);

    Ballot* ballot7 = election2020.getInPersonBallot(471832);

    Ballot* ballot8 = election2020.getMailInBallot(999999); // nem letezo id-khez nullptr
    Ballot* ballot9 = election2020.getInPersonBallot(999999);
    assert(ballot8 == nullptr);
    assert(ballot9 == nullptr);

    ballot1->cast(1);
    ballot2->cast(1); // ervenytelen szavazat!
    ballot3->cast(2);
    // ballot4 nincs!
    ballot5->cast(3); // mivel van a ballot6 is ami inPerson, ez ervenytelen lesz
    ballot6->cast(2);
    ballot7->cast(6);

    election2020.processResults(); // kiirja valamilyen sorrendben, hogy:
    // invalid vote
    // mail ballot rejected for voter 103410
    // mail ballot rejected for voter 314564

    // kiirja hogy:
    // ==============
    // Results for election Valasztas - 2020:
    // Candidate 1 : 1 votes
    // Candidate 2 : 2 votes
    // Candidate 3 : 0 votes
    // ==============
}

int main()
{
    char c;
    for (int i = 0; i < 10; i++) {
        f(); // ha f kilep, a mem.nek fel kell szabadulnia!
        std::cin >> c; // heap profiling celjabol!
    }
}
