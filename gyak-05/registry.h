#pragma once

#include <string>
#include <map>
#include <list>

#include "election.h"

class Voter {
	std::string name;
	std::string city;
	int age;
	int id;
public:
	Voter(const std::string& nm, const std::string& city, int age, int id);
	int getId() { return id; }
	std::string& getName() { return name; }
	void print();
};

class ValasztasiJegyzek {
	std::map<int, Voter*> registry;
	std::map<int, std::map<Election*, bool>> hasVotedInElections;
public:
	~ValasztasiJegyzek();
	void addVoter(Voter*);
	void printVoters();
	void initializeElection(Election&);
	void vote(int voterid, Election& e, int candidate);
};