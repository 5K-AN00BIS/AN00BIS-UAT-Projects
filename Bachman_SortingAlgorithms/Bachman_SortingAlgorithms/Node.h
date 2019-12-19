#ifndef Node_h
#define Node_h

#pragma once
#include <memory>
#include <iostream>

using namespace std;

// Create a templatized node class that we will be working with.
template <class T>
class Node
{
public:
	// Constructor that creates a double node with type T elements and next/previous pointers.
	Node(const T& e = T(), Node* n = NULL, Node* p = NULL) : nodeData(e), next(n), prev(p) {}
	//Deconstructor
	~Node() {}

	// Declare type T elements as well as the next and previous pointers.
	T nodeData; // Generic data type to be stored in the templatized linked list.
	Node* next; // Points to the next node.
	Node* prev; // Points to the previous node.
};

#endif