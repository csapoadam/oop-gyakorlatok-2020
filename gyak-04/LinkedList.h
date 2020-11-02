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

class DynamicList {
protected:
	Node* root;
public:
	DynamicList() : root{nullptr} {}
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
	LifoList(const LifoList&);
	LifoList& operator=(const LifoList&);
	LifoList& addNode(int);
	void print();
};

// klasszikus Linked List
class FifoList : public DynamicList {
	Node* getLastNode();
public:
	FifoList() {}
	FifoList(const FifoList&);
	FifoList& operator=(const FifoList&);
	FifoList& addNode(int);
	void deleteItem(int n); // deletes nth element if it exists!
	void print();
};
