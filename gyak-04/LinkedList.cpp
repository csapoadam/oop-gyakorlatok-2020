#include "LinkedList.h"
#include <iostream>

Node::Node(int val) : next{ nullptr }, value(val) {
}

DynamicList::~DynamicList() {
	std::cout << "Destructor for DynamicList has been called" << std::endl;
	Node* current = root;
	if (current != nullptr) {
		while (current != nullptr) {
			Node* next = current->getNext();
			delete current;
			current = next;
		}
	}
}

DynamicList::DynamicList(const DynamicList& llToCopy) {
	std::cout << "copy constructor for Dynamic List called!" << std::endl;
	// LifoList es FifoList eseteben nem volt u.az a copy constr.
	// ... de csak azert, mert egyik esetben az addNode() metodust hasznaltuk.
	// Ha mindket esetben alapszintubb muveletekkel oldjuk meg,
	// valojaban a ketto u.az!
	if (llToCopy.root == nullptr) {
		root = nullptr; // ha a masolando root nullptr, nincs mit masolni
		// ettol meg root = nullptr be kell allitani, mert ujonnan hozunk letre egy
		// ures DynamicListet!
	}
	else {
		// ellenkezo esetben eloszor a root-ot masoljuk
		root = new Node(llToCopy.root->getValue());

		Node* current = root; // root itt mar letezik!
		Node* currentInLlToCopy = llToCopy.root;

		// amig van tovabbi elem, mindegyikhez keszitunk egy masolatot
		while (currentInLlToCopy = currentInLlToCopy->getNext()) {
			current->setNext(
				new Node(
					currentInLlToCopy->getValue()
				)
			);
			current = current->getNext();
		}
	}
}

LifoList& LifoList::operator=(const LifoList& llToCopy) {
	LifoList deepCopyOfLlToCopy(llToCopy);
	Node* oldroot = this->root;
	this->root = deepCopyOfLlToCopy.root;
	deepCopyOfLlToCopy.root = oldroot;
	return *this;
}

LifoList& LifoList::addNode(int value) {
	// amikor ezt eloszor meghivjuk, root meg nullptr
	if (root == nullptr) {// tehat az uj node amit letrehozunk, az lesz maga a root
		root = new Node(value);// root->next pedig automatikusan nullptr, vagyis tovabbi
		// teendonk nincs!
	}
	else {
		// a masik esetben letrehozzuk az uj node-ot
		Node* newNode = new Node(value); // az uj node nextje a korabbi root
		newNode->setNext(root); // az uj root pedig a most letrehozott node
		root = newNode;
	}
	return *this;
}


void LifoList::print() {
	Node* currentNode = root;
	if (currentNode != nullptr) {
		std::cout << "I am a LIFO list w/ values: ";
		std::cout << currentNode->getValue();
		while (currentNode->getNext() != nullptr) {
			currentNode = currentNode->getNext();
			std::cout << ", " << currentNode->getValue();
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "I am an empty LIFO list" << std::endl;
	}
}

bool LifoList::isLastNode(Node* node) {
	Node* currentNode = root;
	while (true) {
		if (currentNode->getNext() == nullptr) {
			return node == currentNode;
		}
		else {
			currentNode = currentNode->getNext();
		}
	}
}

FifoList& FifoList::operator=(const FifoList& llToCopy) {
	FifoList deepCopyOfLlToCopy(llToCopy);
	Node* oldroot = this->root;
	this->root = deepCopyOfLlToCopy.root;
	deepCopyOfLlToCopy.root = oldroot;
	return *this;
}

void FifoList::deleteItem(int n) {
	if (root != nullptr) {
		if (n == 1) {
			// a root-ot kell torolni... es uj rootot beallitani
			Node* newRoot = root->getNext(); // newRoot a 2. elem cimet tartalmazza
			delete root; // toroljuk a root altal hivatkozott mem.teruletet
			root = newRoot; // root most mar a korabbi 2. elemre mutat
		}
		else {
			// a torlendo node elotti node-janak next-je a torlendo
			// node next-je
			int cnt = 2;
			Node* previous = root;
			Node* current = root->getNext();

			while (true) {
				if (current == nullptr) {
					break; // nincs mit torolni, n nagyobb, mint a lista hossza!
				}
				else {
					if (cnt == n) {
						// torles itt megvalositando!
						previous->setNext(current->getNext()); // current biztosan nem nullptr!
						delete current;
						break;
					}
					else {
						// leptetes tovabb
						cnt++;
						previous = current;
						current = previous->getNext();
					}
				}
			}
		}
	}
}


void FifoList::print() {
	Node* currentNode = root;
	if (currentNode != nullptr) {
		std::cout << "I am a FIFO list w/ values: ";
		std::cout << currentNode->getValue();
		while (currentNode->getNext() != nullptr) {
			currentNode = currentNode->getNext();
			std::cout << ", " << currentNode->getValue();
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "I am an empty Linked list" << std::endl;
	}
}

FifoList& FifoList::addNode(int value) {
	// amikor ezt eloszor meghivjuk, root meg nullptr
	if (root == nullptr) {// tehat az uj node amit letrehozunk, az lesz maga a root
		root = new Node(value);// root->next pedig automatikusan nullptr, vagyis tovabbi
		// teendonk nincs!
	}
	else {
		// a masik esetben letrehozzuk az uj node-ot
		Node* newNode = new Node(value); // az uj node nextje a korabbi root
		Node* lastNode = getLastNode(); // nem kell ellenorizni h lastNode nullptr-e
		// mivel itt mar biztosan van legalabb 1 elem a listaban
		lastNode->setNext(newNode);
	}
	return *this;
}

Node* FifoList::getLastNode() {
	if (root == nullptr) { return nullptr; } // a teljesseg kedveert
	Node* currentNode = root;
	while (currentNode->getNext() != nullptr) {
		currentNode = currentNode->getNext();
	}
	return currentNode;
}