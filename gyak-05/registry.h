#pragma once

#include <string>
#include <map>

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
public:
	void addVoter(Voter*);
	void printVoters();
};