#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#pragma once

#include <stdlib.h>
#include <iostream>

template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree();

	// Copy constructor
	BinarySearchTree(const BinarySearchTree& rhs) : root{ nullptr }
	{
		root = clone(rhs.root);
	}

	BinarySearchTree(BinarySearchTree&& rhs);

	// As usual the destructor calls makeEmpty();
	~BinarySearchTree()
	{
		makeEmpty();
	}

	const Comparable& findMin() const;
	const Comparable& findMax() const;

	// Binary search tree class skeletons.
	// Returns true if x is found in the tree.
	bool contains(const Comparable& x) const
	{
		return contains(x, root);
	}

	bool isEmpty() const;
	void printTree(std::ostream& out = cout) const;

	void makeEmpty();

	// Insert x into the tree; Duplicates are ignored.
	void insert(const Comparable& x)
	{
		insert(x, root);
	}

	void insert(Comparable&& x);

	// Remove x from the tree. Nothing is done if x is not found.
	void remove(const Comparable& x)
	{
		remove(x, root);
	}

	BinarySearchTree& operator=(const BinarySearchTree& rhs);
	BinarySearchTree& operator=(BinarySearchTree&& rhs);

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt) : element{ theElement }, left{ lt }, right{ rt } {}

		BinaryNode(Comparable&& theElement, BinaryNode* lt, BinaryNode* rt) : element{ std::move(theElement) }, left{ lt }, right{ rt } {}
	};

	BinaryNode* root;

	// Internal method to insert into a subtree. X is the item to insert. t is the node that roots the subtree. Set the new root of the subtree.
	void insert(const Comparable& x, BinaryNode*& t)
	{
		if (t == nullptr)
		{
			t = new BinaryNode{ x, nullptr, nullptr };
		}
		else if (x < t->element)
		{
			insert(x, t->left);
		}
		else if (t->element < x)
		{
			insert(x, t->right);
		}
		else
		{
			; // Duplicate; do nothing.
		}
	}

	// Internal method to insert into a subtree. x is the item to insert by moving. t is the node that roots to the subtree. Set the new root.
	void insert(Comparable&& x, BinaryNode*& t)
	{
		if (t == nullptr)
		{
			t = new BinaryNode{ std::move(x), nullptr, nullptr };
		}
		else if (x < t->element)
		{
			insert(std::move(x), t->left);
		}
		else if (t->element < x)
		{
			insert(std::move(x), t->right);
		}
		else
		{
			; // Duplicate; do nothing.
		}
	}

	// Internal method to remove from a subtree. x is the item to remove. t is the node that roots the subtree. Set the new root of the subtree.
	void remove(const Comparable& x, BinaryNode*& t)
	{
		if (t == nullptr)
		{
			return; // Item not found; do nothing.
		}

		if (x < t->element)
		{
			remove(x, t->left);
		}
		else if (t->element < x)
		{
			remove(x, t->right);
		}
		else if (t->left != nullptr && t->right != nullptr) // Two children
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else
		{
			BinaryNode* oldNode = t;
			t = (t->left != nullptr) ? t->left : t->right;
			delete oldNode;
		}
	}

	// Internal method to find the smallest item in a subtree t. Return the node containing the smallest item.
	BinaryNode* findMin(BinaryNode* t) const
	{
		if (t == nullptr)
		{
			return nullptr;
		}
		if (t->left == nullptr)
		{
			return t;
		}

		return findMin(t->left);
	}

	// Internal method to find the largest item in a subtree t. Return node containing the largest item.
	BinaryNode* findMax(BinaryNode* t) const
	{
		if (t != nullptr)
		{
			while (t->right != nullptr)
			{
				t = t->right;
			}
		}

		return t;
	}

	// Internal method to test if an item is in a subtree. x is item to search for. T is the node the that roots the subtree.
	bool contains(const Comparable& x, BinaryNode* t) const
	{
		// Order is important. It is crucial to test for empty first, otherwise a run time error will occur fir accessubg a data member through a nullptr
		// The rest are in order from least likely case last.
		if (t == nullptr)
		{
			return false;
		}
		else if (x < t->element)
		{
			return contains(x, t->left);
		}
		else if (t->element < x)
		{
			return contains(x, t->right);
		}
		else
		{
			return true; // Match.
		}
	}

	// Internal method to make subtree empty.
	void makeEmpty(BinaryNode*& t)
	{
		if (t != nullptr)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}

		t = nullptr;
	}

	void printTree(BinaryNode* t, std::ostream& out) const;

	// Internal method to clone subtree.
	BinaryNode& clone(BinaryNode* t) const
	{
		if (t == nullptr)
		{
			return nullptr;
		}
		else
		{
			return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
		}
	}
};

#endif