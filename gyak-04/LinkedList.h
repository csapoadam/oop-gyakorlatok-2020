#pragma once

#include <iostream>

class Node {
	int value;
	Node* next;
public:
	Node(int);
	int getValue() { return value; }
	Node* getNext() { return next; }
	void setNext(Node* n) { next = n; }
};

class DynamicList {
protected:
	Node* root;
public:
	DynamicList() : root{nullptr} {}
	DynamicList(const DynamicList&);
	// delete kikenyszeriti, hogy a gyermek vagy megvalositja,
	// vagy a gyermek nem masolhato =-jellel:
	DynamicList& operator=(const DynamicList&) = delete;
	~DynamicList();
};

// olyan mint egy FifoList, de az uj elemeket mindig az
// elejere szurjuk be... ezert pl. amikor printelunk, forditott
// sorrendben olvassuk ki az ertekeket (mint a hozzaadas sorrendje)
// LIFO = Last in, first out
class LifoList : public DynamicList {
	bool isLastNode(Node*);
public:
	LifoList() {}
	LifoList(const LifoList& other) : DynamicList(other) {
		// ha LifoListnek barmilyen okbol sajat copy constr-ra lenne szuksege
		// akkor ugyelnunk kell ra, hogy az inicializalo listaban meghivjuk
		// a szulo copy construktorat is!
		// -> copy constructor ugyanolyan, mint egy sima mezei konstruktor
		std::cout << "copy constructor for LifoList called..." << std::endl;
		// ez csak egy szemlelto pelda, jelenleg nincs szukseg sajat copy constr-ra itt!
	}
	LifoList& operator=(const LifoList&);
	LifoList& addNode(int);
	void print();
};

// klasszikus Linked List
class FifoList : public DynamicList {
	Node* getLastNode();
public:
	FifoList& addNode(int);
	// itt nincs copy construktor, tehat automatikusan a szuloe hivodik meg!
	// FifoList mynewFList(myAlreadyExistingFifoList); // azt jelenti, hogy egy DynamicListet is letrehozok vegso soron
	FifoList& operator=(const FifoList&);
	void deleteItem(int n); // deletes nth element if it exists!
	void print();
};
