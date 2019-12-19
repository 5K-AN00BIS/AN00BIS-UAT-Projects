// Ryan Bachman
// University of Advancing Technology
// CSC382 - Data Structures and Algorithms
// Assignment - Project: Binary Search Tree (AVL)

/*In this lab, you will implement a binary search tree data structure in the language of your choice, and turn in a program evaluating the data structure.

Implement a templated Binary Search Tree data structure, implementing the following functionality:

Insert (insert the specified value into the BST)
Delete (delete given node, restructure the tree accordingly so no other data is removed or lost)
Maximum (Find maximum value in the BST)
Traverse (Traverse the tree and return the data in the order of traversal. You can implement either inorder, preorder, or postorder traversal.)
To evaluate this data structure, write your program to read from an array of unsorted integers. 
You could also read from a data file (with the filename passed as a command line parameter) and populates the data structure.

Rigorous testing is expected! Be sure to include tests for attempting to remove a node from an empty BST, attempting to insert a duplicate node, removing a node with no children, removing a node with one child, and removing a node with two children. Be sure to verify the BST organization and structure are correct.


BONUS - Performance Analysis of your Binary Tree (+4 pts)

Conduct a performance analysis of your BST and record the amount of time it takes to do Add and Remove the following:

100 nodes
1000 nodes
10000 nodes
100000 nodes
Display your data in a data table and graph the results.

BONUS - Self-Balancing (AVL) Binary Search Tree (+6 pts)
Implement a  Self-Balancing Binary Search Tree (Links to an external site.).  

Evaluate the performance of this data structure as compared to the normal binary search tree on adding and removing 100, 1000, 10000, and 100000 nodes.*/

// Preprocessor Directives
#include "Interface.h"

// Global Declarations (if any)

int main()
{
	// Call the menu function from Interface.h
	Interface();

	system("pause"); // Stops before quitting the program.
	return 0;
}