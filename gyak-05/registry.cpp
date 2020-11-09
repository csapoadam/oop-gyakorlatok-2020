#include "registry.h"
#include <iostream>

Voter::Voter(const std::string& nm,
	const std::string& city, int age, int id) :
	
	name{ nm }, city{ city }, age{age}, id{id} {}

void Voter::print() {
	std::cout << id << ": " << name << " -- " << age << " yrs old -- " << city << std::endl;
}

void ValasztasiJegyzek::addVoter(Voter* v) {
	auto successPair = registry.insert(
	//std::pair<std::map<int, Voter*>::iterator, bool> successPair = registry.insert(
		//std::make_pair(v->getId(), v)
		{v->getId(), v}
	);
	if (!successPair.second) {
		std::cout << " ---> could not add voter: ";
		v->print();
		std::cout << "    > because voter by name ";
		std::cout << (*successPair.first).second->getName();
		std::cout << " has the same id!" << std::endl;

		// torolni is kell ezt a mem.teruletet, mert a destruktor nem fogja...
		delete v;
	}
	else {
		hasVotedInElections.insert({
			v->getId(), std::map<Election*, bool>()
		});
	}
}

void ValasztasiJegyzek::printVoters() {
	/*for (auto it = registry.begin(); it != registry.end(); it++) {
		(*it).second->print();
	}*/
	// vagy pedig igy:
	//for (std::pair<int, Voter*> keyValPair : registry) {
	for (auto keyValPair : registry) {
		int voterId = keyValPair.first;
		keyValPair.second->print();
		auto hasVotedInfo = hasVotedInElections[voterId];
		for (auto electionsVotes : hasVotedInfo) {
			if (electionsVotes.second) {
				std::cout << "  ... has voted in ";
				std::cout << electionsVotes.first->getName();
				std::cout << std::endl;
			}
		}
	}
}

ValasztasiJegyzek::~ValasztasiJegyzek() {
	for (auto keyValPair : registry) {
		delete keyValPair.second;
	}
}

void ValasztasiJegyzek::initializeElection(Election& e) {
	for (auto registryIdsAndVoters : registry) {
		int voterId = registryIdsAndVoters.first;
		hasVotedInElections[voterId].insert(
			{&e, true} // false kellene, de a teszt kedveert legyen true
		);
	}
}