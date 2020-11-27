#pragma once

#include <string>
#include <map>
#include <list>
#include <set>

class Registry {
	class Voter {
		std::string name;
		std::string city;
		int age;
		int id;
	public:
		Voter(const std::string& name, const std::string& city, int age, int id);
		int getId() const { return id; }
		const std::string& getName() const { return name; }
		void print() const;
	};

	std::map<int, Voter*> registry;
public:
	~Registry();
	void addVoter(const std::string& name, const std::string& city, int age, int id);
	void printVoters() const;
	bool hasVoterById(int id) const {
		return registry.find(id) != registry.end();
	}
};

class Election;

class Ballot {
	friend class Election;
protected:
	Election& election;
	int vote;
	Ballot(Election& e) : election(e), vote{ -1 } {}
public:
	virtual void cast(int vote) = 0;
	virtual ~Ballot() {}
};

class InPersonBallot : public Ballot {
	friend class Election;
	// nem tartalmazza a szavazo id-jet! csak 1x szabad kiadni per szavazo!
	InPersonBallot(Election& e) : Ballot{ e } {}
public:
	void cast(int candidate) override; 
	InPersonBallot(const InPersonBallot&) = delete;
};

class MailInBallot : public Ballot {
	friend class Election;
	int voterId;
	MailInBallot(Election& e, int voterId) : Ballot(e), voterId(voterId) {}
public:
	void cast(int candidate) override;
	MailInBallot(const MailInBallot&) = delete;
};

class Election {
	friend class InPersonBallot;
	friend class MailInBallot;

	std::string electionName;
	int numberOfCandidates;
	Registry& registry;

private:
	std::list<Ballot*> registeredBallots;
	std::list<InPersonBallot*> urn;
	std::list<MailInBallot*> mailins;
	std::set<int> voterIdsVoted;

	void registerBallot(Ballot* b) { registeredBallots.push_back(b); }

	void submitBallotInPerson(InPersonBallot* bp) { urn.push_back(bp); }
	void receiveMailInBallot(MailInBallot* mibp) { mailins.push_back(mibp); }

public:
	Election(const std::string& name, int numberOfCandidates, Registry& r);
	~Election();
	const std::string& getName() const { return electionName; }
	int getNumberOfCandidates() const { return numberOfCandidates; }

	InPersonBallot* getInPersonBallot(int voterid) {
		if (registry.hasVoterById(voterid)) {
			if (voterIdsVoted.find(voterid) == voterIdsVoted.end()) {
				voterIdsVoted.insert(voterid);
				InPersonBallot* ipbp = new InPersonBallot(*this);
				registerBallot(ipbp);
				return ipbp;
			}
		}
		// voter has already voted (or does not exist in registry)!
		return nullptr;
	}

	MailInBallot* getMailInBallot(int voterid) {
		if (registry.hasVoterById(voterid)) {
			MailInBallot* mibp = new MailInBallot(*this, voterid);
			registerBallot(mibp);
			return mibp;
		}
		else {
			return nullptr;
		}
	}

	void processResults();
};



