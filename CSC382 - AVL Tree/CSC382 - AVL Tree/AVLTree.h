#pragma once

// Create the templated node class as a structure.
template <typename Comparable>
struct AvlNode
{
	Comparable element;
	AvlNode* left;
	AvlNode* right;
	int height;

	// Create a const node.
	AvlNode(const Comparable& ele, AvlNode* lt, AvlNode* rt, int h = 0)
		: element{ ele }, left{ lt }, right{ rt }, height{ h } {}

	// Create node.
	AvlNode(Comparable& ele, AvlNode* lt, AvlNode* rt, int h = 0)
		: element{ ele }, left{ lt }, right{ rt }, height{ h } {}

	// Function to return the height of node t or -1 if nullptr is returned.
	int height(AvlNode* t) const
	{
		return t == nullptr ? -1 : t->height;
	}

	// Internal method to insert into a subtree. x is the item to insert. t is the node that roots the subtree. Set the new root of the subtree.
	void insert(const Comparable& x, AvlNode*& t)
	{
		if (t == nullptr)
		{
			t = new AvlNode(x, nullptr, nullptr);
		}
		else if (x < t->element)
		{
			insert(x, t->left);
		}
		else if (t->element < x)
		{
			insert(x, t->right);
		}

		balance(t);
	}

	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced.
	void balance(AvlNode*& t)
	{
		if (t == nullptr)
		{
			return; // Return nothing.
		}

		if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
		{
			if (height(t->left->left) >= height(t->left->right))
			{
				rotateWithLeftChild(t);
			}
			else
			{
				doubleWithLeftChild(t);
			}
		}
		else
		{
			if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
			{
				if (height(t->right->right) >= height(t->right->left))
				{
					rotateWithRightChild(t);
				}
				else
				{
					doubleWithRightChild(t);
				}
			}
		}

		t->height = max(height(t->left), height(r->right)) + 1;
	}

	// Rotate the binary tree node with left child. For AVL trees, this is a single rotation for case 1.
	// Update heights, then set a new root.
	void rotateWithLeftChild(AvlNode*& k2)
	{
		AvlNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = max(height(k2->left), height(k2->right)) + 1;
		k1->height = max(height(k1->left), k2->height) + 1;
		k2 = k1;
	}

	// Rotate the binary tree node with left child. For AVL trees, this is a single rotation for case 1.
	// Update heights, then set a new root.
	void rotateWithRightChild(AvlNode*& k2)
	{
		AvlNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = max(height(k2->left), height(k2->right)) + 1;
		k1->height = max(height(k1->left), k2->height) + 1;
		k2 = k1;
	}

	// Double rotate binary tree node: first left child with its right child, then node k3 with new left child.
	// For AVL trees, this is a double rotation for case 2. Update heights, then set a new root.
	void doubleWithLeftChild(AvlNode*& k3)
	{
		rotateWithRightChild(k3->left);
		rotateWithLeftChild(k3);
	}

	// Double rotate binary tree node: first left child with its right child, then node k3 with new left child.
	// For AVL trees, this is a double rotation for case 2. Update heights, then set a new root.
	void doubleWithRightChild(AvlNode*& k3)
	{
		rotateWithRightChild(k3->left);
		rotateWithLeftChild(k3);
	}

	// Internal method to remove from a subtree. X is the item to remove. T is the node that roots the subtree. Set the new root.
	void remove(const Comparable& x, AvlNode*& t)
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
		else if (t->left != nullptr && t->right != nullptr) // Two children.
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else
		{
			AvlNode* oldNode = t;
			t = (t->left != nullptr) ? t->left : t->right;
			delete oldNode;
		}

		balance(t);
	}
};