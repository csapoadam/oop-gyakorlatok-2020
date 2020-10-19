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