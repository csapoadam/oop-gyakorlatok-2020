#pragma once

class Election {
	int numberOfCandidates;
	std::string name;
public:
	Election(const std::string& nm, int noc) :
		name{nm}, numberOfCandidates(noc) {}
	std::string& getName() { return name; }
};
