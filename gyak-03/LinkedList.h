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
	bool isLastNode(Node*);
public:
	LifoList() : root(nullptr) {}
	LifoList& addNode(int);
	void print();
};

// klasszikus Linked List
class LinkedList {
	Node* root;
	Node* getLastNode();
public:
	LinkedList() : root(nullptr) {}
	LinkedList(const LinkedList&);
	~LinkedList();
	LinkedList& addNode(int);
	void deleteItem(int n); // deletes nth element if it exists!
	void print();
};