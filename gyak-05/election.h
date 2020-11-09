#pragma once

class Election {
	int numberOfCandidates;
	std::string name;
	std::map<int, int> votesForEachCandidate;
public:
	Election(const std::string& nm, int noc) :
			name{nm}, numberOfCandidates(noc) {
		for (int candnum = 1; candnum < numberOfCandidates + 1; candnum++) {
			votesForEachCandidate.insert({
				candnum, 0
			});
		}
	}
	std::string& getName() { return name; }
	void addVoteForCandidate(int candidateNumber) {
		(*(votesForEachCandidate.find(candidateNumber))).second += 1;
	}
	void printResults() {
		std::cout << "==============" << std::endl;
		std::cout << "Results for election " << name << ":" << std::endl;
		for (auto candvotes : votesForEachCandidate) {
			std::cout << "Candidate " << candvotes.first << ": ";
			std::cout << candvotes.second << " votes" << std::endl;
		}
		std::cout << "==============" << std::endl;
	}
};
