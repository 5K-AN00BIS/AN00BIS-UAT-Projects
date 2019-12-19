#ifndef Iterator_h
#define Iterator_h

#pragma once
#include <stdlib.h>
#include "Node.h"

// Create an iterator so that we can traverse around the nodes both ways.
template <class T>
class Iterator
{
private:
	// Used to track the current node that is selected.
	Node<T>* currentNode;

public:
	// Constructor
	Iterator(Node<T>* node = NULL) : currentNode(node) {}

	// Deconstructor
	~Iterator()
	{
		if (currentNode == NULL)
		{
			currentNode = NULL;
		}
	}

	// Iterates to the next node in the list.
	Node<T>* nextNode()
	{
		if (currentNode == NULL)
		{
			return NULL;
		}

		currentNode = currentNode->next;
		return currentNode;
	}

	// Iterates to the previous node in the list.
	Node<T>* previousNode()
	{
		if (currentNode == NULL)
		{
			return NULL;
		}

		currentNode = currentNode->prev;
		return currentNode;
	}
};

#endif