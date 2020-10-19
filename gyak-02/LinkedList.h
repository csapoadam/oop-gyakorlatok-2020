#pragma once

class Node {
	int value;
	Node* next;
public:
	Node(int);
	int getValue() { return value; }
	Node* getNext() { return next; }
	void setNext(Node* n) { next = n; }
};

// olyan mint egy LinkedList, de az uj elemeket mindig az
// elejere szurjuk be... ezert pl. amikor printelunk, forditott
// sorrendben olvassuk ki az ertekeket (mint a hozzaadas sorrendje)
// LIFO = Last in, first out
class LifoList {
	Node* root;
public:
	LifoList() : root(nullptr) {}
	LifoList& addNode(int);
	void print();
	bool isLastNode(Node*);
};