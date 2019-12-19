#include "Interface.h"

using namespace std;

// Build out the testing suite. Not quite sure how to do this, but wanted it in the code so I could at least start on it.
bool LinkedListTestingSuite()
{
	// Starts off the test_success as true so it's guaranteed to run at least once and resets whenever called.
	bool test_success = true;

	// Create a new LinkedList for testing
	LinkedList<int>* testingList = new LinkedList<int>();

	// Check to see if the list is created empty as intended.
	if (testingList->isEmpty())
	{
		cout << "The list was created and is empty as needed." << endl;
	}
	else
	{
		cout << "Something was on the ship the whole time. This list didn't create empty." << endl;
		test_success = false; // Set test_success to false so we can let the user know something failed.
	}

	return test_success;
}

// Interface with the user to let them know if tests were good or not.
bool TestingSuite()
{
	system("cls"); // Clear the screen for the user.
	bool list_test_status = LinkedListTestingSuite();

	if (list_test_status) // If the status is successful and the bool is still true
	{
		cout << "All tests were run successfully. Everything is working as intended!\n" << endl;
		return true;
	}
	else // Something failed in the testing so test_success is set to false.
	{
		cout << "At least one test has failed! Uh oh!\n" << endl;
		return false;
	}
}

// Creates the interface class, which will be the meat and potatoes of this entire program.
void Interface()
{
	// Create a new LinkedList for integers in this scenario.
	LinkedList<int>* numberList = new LinkedList<int>();

	// Create a new variable to store user menu integer.
	int menuSelection = -1;
	// Input value
	char input[6];
	int hold; // Holds the value of input in some scenarios.

	// While loop to resurface the menu as long as the user does not want to exit the program.
	while (menuSelection != 0)
	{
		// Displays the menu to the user and asks for input to traverse the settings.
		cout << "Welcome to Ryan Bachman's Linked List project for CSC382!" << endl;
		cout << "Please select what you'd like to do in the menu below using the designated numbers in parentheses." << endl;
		cout << "(1) Find information in the linked list." << endl;
		cout << "(2) Insert a node." << endl;
		cout << "(3) Delete a selected node." << endl;
		cout << "(4) Print the contents of the nodes." << endl;
		cout << "(5) Automated Testing Suite" << endl;
		cout << "(0) Exit the program." << endl;
		cout << "\nPlease enter the number corresponding to the action you want to take: ";
		cin >> menuSelection;

		// Switch for menu selection and interaction.
		switch (menuSelection)
		{
		case 1: // If menuSelection is equal to 1.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've elected to find info.\n" << endl;
			// Ask user for input
			cout << "Please enter the integer you want to find in the list: " << endl;
			cin >> input;
			hold = atoi(input); // Convert string input to integer for this assignment.

			// Check to see if the linked list is empty first.
			if (numberList->isEmpty())
			{
				cout << "There is nothing to search. It's empty! Try adding nodes by using 2 in menu!\n" << endl;
			}
			else // If not empty, use the LinkedList search function to find out if information has been found in the list.
			{
				numberList->findNode(hold); // Call the search function.
			}

			break; // End the case.
		}
		case 2: // If menuSelection is equal to 2.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've elected to insert a node.\n" << endl;
			// Ask user for input
			cout << "Please insert an integer: ";
			cin >> input;
			hold = atoi(input); // Convert string input to integer for this assignment.

			// First check to see if the list is empty using our IsEmpty() function from LinkedList.h
			if (numberList->isEmpty())
			{
				// If so, we will insert the first value to make a node.
				numberList->insertAtTail(hold);
			}
			else
			{
				// If so, we will insert the first value to make a node.
				numberList->insertAtTail(hold);
			}

			break; // End the case.
		}
		case 3: // If menuSelection is equal to 3.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've elected to delete a node.\n" << endl;
			// Ask user for input
			cout << "Enter the number you want to delete from the list: ";
			cin >> input;
			hold = atoi(input); // Convert string input to integer for this assignment.

			// Initiates the iterator at the head to get it ready for work.
			Iterator<int>* i = numberList->iteratorHead();
			Node<int>* search;

			// Searches nodes for the value that is needing removal
			while ((search = i->nextNode()) != NULL)
			{
				if (search->nodeData == hold)
				{
					// Stop the loop if it found the number the user searched
					break;
				}
			}

			if (search == NULL)
			{
				// Let the user know if the value was not found in the linked list.
				cout << "The value was either not found or the list was empty. Try adding it using 2 in the menu!\n" << endl;
			}
			else
			{
				// Remove if from the list if it's found.
				if (numberList->removeNode(search))
				{
					cout << "The value has been removed successfully!\n" << endl;
				}
				else // Catches for a generic error.
				{
					cout << "Unknown failure." << endl;
				}
			}

			delete i; // Delete the iterator to free up memory.
			break; // End the case.
		}
		case 4: // If menuSelection is equal to 4.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "Printing the nodes...\n" << endl;

			// Check to see if the list is empty, otherwise print out all of the nodes.
			if (numberList->isEmpty())
			{
				cout << "The list is empty! Try adding to it by selecting 2 from the menu.\n" << endl;
			}
			else
			{
				cout << endl << "Integers in the list:" << endl;

				// Uses the iterator to list all the numbers.
				Iterator<int>* i = numberList->iteratorHead();
				Node<int>* list;

				// List all of the nodes.
				while ((list = i->nextNode()) != NULL)
				{
					cout << list->nodeData << endl;
				}
				cout << endl;

				// Delete the iterator once done to free up memory.
				delete i;
			}

			break; // End the case.
		}
		case 5: // If menuSelection is equal to 5.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've started the Automated Testing Suite.\n" << endl;
			TestingSuite();
			break;
		}
		case 0: // If menuSelection is equal to 0.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "Closing the program.\n" << endl;
			break;
		}
		default: // If menuSelection is equal to anything else.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "Incorrect selection. Please use the numbers in parentheses to interact with the menu.\n" << endl;
			break;
		}
		}

	}
}