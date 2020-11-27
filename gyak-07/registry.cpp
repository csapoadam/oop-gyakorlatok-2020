#include <iostream>
#include "registry.h"

Registry::Voter::Voter(const std::string& name, const std::string& city, int age, int id) :
	name{ name }, city{ city }, age{age}, id{id} {}

void Registry::Voter::print() const {
	std::cout << id << ": " << name << " -- " << age << " yrs old -- " << city << std::endl;
}

void Registry::addVoter(const std::string& name, const std::string& city, int age, int id) {
	Voter* newVoter = new Voter(name, city, age, id);

	auto successPair = registry.insert({ id, newVoter });
	if (!successPair.second) { // bool ertek, hogy sikerult-e a beszuras attol fuggoen h a kulcs egyedi-e!
		std::cout << " ---> could not add voter: ";
		newVoter->print();
		std::cout << "    > because voter by name ";
		std::cout << (*successPair.first).second->getName();
		std::cout << " has the same id!" << std::endl;
		// torolni is kell ezt a mem.teruletet, mert a destruktor nem fogja...
		delete newVoter;
	}
}

void Registry::printVoters() const {
	for (auto keyValPair : registry) {
		keyValPair.second->print();
	}
}

Registry::~Registry() {
	for (auto keyValPair : registry) {
		delete keyValPair.second;
	}
}

Election::Election(const std::string& nm, int numberOfCandidates, Registry& r) :
	electionName{ nm }, numberOfCandidates(numberOfCandidates), registry{r} {
}

Election::~Election() {
	for (Ballot* bp : registeredBallots) {
		delete bp;
	}
}

void InPersonBallot::cast(int candidate) {
	vote = candidate;
	election.submitBallotInPerson(this);
}

void MailInBallot::cast(int candidate) {
	vote = candidate;
	election.receiveMailInBallot(this);
}

void Election::processResults() {
	std::map<int, int> votesForEachCandidate;

	for (int candnum = 1; candnum < numberOfCandidates + 1; candnum++) {
		votesForEachCandidate.insert({
			candnum, 0
		});
	}


	for (InPersonBallot* bp : urn) {
		if (bp->vote > 0 && bp->vote < numberOfCandidates + 1) {
			(*(votesForEachCandidate.find(bp->vote))).second += 1;
		}
		else {
			std::cout << "invalid vote" << std::endl;
		}
	}

	for (MailInBallot* bp : mailins) {
		if (voterIdsVoted.find(bp->voterId) == voterIdsVoted.end()) {
			voterIdsVoted.insert(bp->voterId);
			if (bp->vote > 0 && bp->vote < numberOfCandidates + 1) {
				(*(votesForEachCandidate.find(bp->vote))).second += 1;
			}
			else {
				std::cout << "invalid mail in vote" << std::endl;
			}
		}
		else {
			std::cout << "mail ballot rejected for voter " << bp->voterId << std::endl;
		}
	}

	std::cout << "==============" << std::endl;
	std::cout << "Results for election " << electionName << ":" << std::endl;
	for (auto candvotes : votesForEachCandidate) {
		std::cout << "Candidate " << candvotes.first << ": ";
		std::cout << candvotes.second << " votes" << std::endl;
	}
	std::cout << "==============" << std::endl;
}
