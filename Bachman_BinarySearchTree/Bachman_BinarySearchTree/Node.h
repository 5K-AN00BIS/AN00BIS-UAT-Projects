#ifndef Node_h
#define Node_h

#pragma once
#include <iostream>
#include <memory>

// Create a templatized node class that we will be working with in the AVL tree.
template <class T>
class Node
{
public:
	T value; // Creates the data key for the node under T type so it can be templated.
	int balance; // Used to keep track of balance.
	Node* left;
	Node* right;
	Node* parent;

	// Constructor to build a blank node that can be filled by the program.
	Node(T v, Node* p) : value(v), balance(0), parent(p), left(NULL), right(NULL) {}

	// Destructor to clear memory
	~Node()
	{
		// Delete left and right to clear memory space.
		delete left;
		delete right;
	}
};

#endif