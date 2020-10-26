#include "LinkedList.h"
#include <iostream>

Node::Node(int val) : next{ nullptr }, value(val) {
}

LifoList& LifoList::addNode(int value) {
	// amikor ezt eloszor meghivjuk, root meg nullptr
	if (root == nullptr) {// tehat az uj node amit letrehozunk, az lesz maga a root
		root = new Node(value);// root->next pedig automatikusan nullptr, vagyis tovabbi
		// teendonk nincs!
	} else {
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


LinkedList::LinkedList(const LinkedList& llToCopy) {
	if (llToCopy.root == nullptr) {
		root = nullptr;
	}
	else {
		Node* current = llToCopy.root;
		addNode(current->getValue());
		while (current->getNext() != nullptr) {
			current = current->getNext();
			addNode(current->getValue());
		}
	}
}

void LinkedList::deleteItem(int n) {
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
			// HAZIFELADAT!
		}
	}
}


void LinkedList::print() {
	Node* currentNode = root;
	if (currentNode != nullptr) {
		std::cout << "I am a Linked list w/ values: ";
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

LinkedList& LinkedList::addNode(int value) {
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

Node* LinkedList::getLastNode() {
	if (root == nullptr) { return nullptr; } // a teljesseg kedveert
	Node* currentNode = root;
	while (currentNode->getNext() != nullptr) {
		currentNode = currentNode->getNext();
	}
	return currentNode;
}