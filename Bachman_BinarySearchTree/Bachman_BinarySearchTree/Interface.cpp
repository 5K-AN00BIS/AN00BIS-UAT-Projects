#include "Interface.h"

// Build out the testing suite. Not quite sure how to do this, but wanted it in the code so I could at least start on it.
bool AVLTreeTestingSuite()
{
	// Starts off the test_success as true so it's guaranteed to run at least once and resets whenever called.
	bool test_success = true;

	// Create a new LinkedList for testing
	AVLTree<int>* testingTree = new AVLTree<int>();

	// Check to see if the list is created empty as intended.
	if (true) // CHANGE THIS LATER
	{
		std::cout << "The tree was created and is empty as needed." << std::endl;
	}
	else
	{
		std::cout << "Something was on the ship the whole time. This list didn't create empty." << std::endl;
		test_success = false; // Set test_success to false so we can let the user know something failed.
	}

	return test_success;
}

// Interface with the user to let them know if tests were good or not.
bool TestingSuite()
{
	std::system("cls"); // Clear the screen for the user.
	bool list_test_status = AVLTreeTestingSuite();

	if (list_test_status) // If the status is successful and the bool is still true
	{
		std::cout << "All tests were run successfully. Everything is working as intended!\n" << std::endl;
		return true;
	}
	else // Something failed in the testing so test_success is set to false.
	{
		std::cout << "At least one test has failed! Uh oh!\n" << std::endl;
		return false;
	}
}

// Creates the Interface class, which will be the main driver for the entirety of this program.
void Interface()
{
	// Create a new AVLTree for integers in this scenario.
	AVLTree<int>* numberTree = new AVLTree<int>();

	// Create a new variable to store user menu integer.
	int menuSelection = -1;
	// Input value
	char input[6];
	int hold; // Holds the value of input in some scenarios.

	// While loop to resurface the menu as long as the user does not want to exit the program.
	while (menuSelection != 0)
	{
		// Displays the menu to the user and asks for input to traverse the settings.
		std::cout << "Welcome to Ryan Bachman's AVL Tree project for CSC382!" << std::endl;
		std::cout << "Please select what you'd like to do in the menu below using the designated numbers in parentheses." << std::endl;
		std::cout << "(1) Insert a node in the tree" << std::endl;
		std::cout << "(2) Delete a node." << std::endl;
		std::cout << "(3) Find the maximum value in the tree." << std::endl;
		std::cout << "(4) Traverse the tree." << std::endl;
		std::cout << "(5) Print the tree." << std::endl;
		std::cout << "(6) Automated Testing Suite" << std::endl;
		std::cout << "(0) Exit the program." << std::endl;
		std::cout << "\nPlease enter the number corresponding to the action you want to take: ";
		std::cin >> menuSelection;

		// Switch for menu selection and interaction.
		switch (menuSelection)
		{
		case 1: // If menuSelection is equal to 1.
		{
			system("cls"); // Clear the screen for a clean interface.
			std::cout << "You've elected to insert a node.\n" << std::endl;
			// Ask user for input
			std::cout << "Please enter the amount of nodes you want in the tree: ";
			std::cin >> input;
			hold = atoi(input); // Convert string input to integer for this assignment.

			// For loop to insert numbers into the tree using the insert function.
			for (int i = 1; i <= hold; ++i)
			{
				numberTree->insert(i); // Should add a number every time i counts so that it's easy to test.
			}

			break; // End the case.
		}
		case 2: // If menuSelection is equal to 2.
		{
			system("cls"); // Clear the screen for a clean interface.
			std::cout << "You've elected to insert a node.\n" << std::endl;
			// Ask user for input
			std::cout << "Please insert an integer: ";
			std::cin >> input;
			hold = atoi(input); // Convert string input to integer for this assignment.

			break; // End the case.
		}
		case 3: // If menuSelection is equal to 3.
		{
			system("cls"); // Clear the screen for a clean interface.
			std::cout << "You've elected to delete a node.\n" << std::endl;
			// Ask user for input
			std::cout << "Enter the number you want to delete from the list: ";
			std::cin >> input;
			hold = atoi(input); // Convert string input to integer for this assignment.


			break; // End the case.
		}
		case 4: // If menuSelection is equal to 4.
		{
			system("cls"); // Clear the screen for a clean interface.
			std::cout << "Printing the nodes...\n" << std::endl;

			break; // End the case.
		}
		case 5: // If menuSelection is equal to 5.
		{
			system("cls"); // Clear the screen for a clean interface.
			std::cout << "Printing the tree...\n" << std::endl << std::endl;
			numberTree->print();

			break; // End the case.
		}
		case 6: // If menuSelection is equal to 6.
		{
			system("cls"); // Clear the screen for a clean interface.
			std::cout << "You've started the Automated Testing Suite.\n" << std::endl;
			TestingSuite();
			break;
		}
		case 0: // If menuSelection is equal to 0.
		{
			system("cls"); // Clear the screen for a clean interface.
			std::cout << "Closing the program.\n" << std::endl;
			break;
		}
		default: // If menuSelection is equal to anything else.
		{
			system("cls"); // Clear the screen for a clean interface.
			std::cout << "Incorrect selection. Please use the numbers in parentheses to interact with the menu.\n" << std::endl;
			break;
		}
		}

	}
}