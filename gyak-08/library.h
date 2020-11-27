#pragma once

#include <vector>

class Publication {
public:
	virtual void print() = 0;
	virtual ~Publication() {
		std::cout << "publication destructor called" << std::endl;
	}
};

class Book : public Publication {
	const std::string title;
	const std::string author;
public:
	Book(const std::string& title, const std::string& author) : title(title), author(author) {}
	~Book() {
		std::cout << "book destructor called" << std::endl;
	}
	void print() override {
		std::cout << "\"" << title << "\"" << " by " << author << std::endl;
	}
};

class Magazine : public Publication {
	const std::string title;
	const int volume;
	const int number;
public:
	Magazine(const std::string& title, int vol, int num) : title(title), volume(vol), number(num) {}
	~Magazine() {
		std::cout << "magazine destructor called" << std::endl;
	}
	void print() override {
		std::cout << "\"" << title << "\"" << ", vol. " << volume << ", no. " << number << std::endl;
	}
	const std::string& getTitle() { return title; }
};

class Library {
	std::vector<Publication*> publications;
	std::vector<void(*)(Magazine*)> magazineHandlers;
public:
	Library() {}
	~Library() {
		for (auto pub : publications) {
			delete pub;
		}
	}
	void addMagazineEventHandler(void (*fp)(Magazine*)) {
		magazineHandlers.push_back(fp);
	}
	void addPublication(Publication* pub) {
		publications.push_back(pub);
		if (Magazine* mag = dynamic_cast<Magazine*>(pub)) {
			for (auto mh : magazineHandlers) {
				mh(mag);
			}
		}
	}
	void print() {
		std::cout << "====" << std::endl << "Contents of library:" << std::endl;
		for (auto pub : publications) {
			pub->print();
		}
	}
};

