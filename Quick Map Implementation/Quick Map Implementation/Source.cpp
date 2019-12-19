#include <stdlib.h>
#include <time.h>
#include <map>
#include <iostream>

// https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean
// Used for processing command line arguments. 
// In short, argc is the number of arguments being passed into the program from the command line.
// argv is the array of arguments.
int main(int argc, char* argv[])
{
	// Creates a new map with two templated type. Char to access the key and int is what it will be returning.
	std::map<char,int> myMap;
	int count;

	srand(time(0));

	// Adds the 1337 elements to the a char key in the map.
	myMap['a'] = 1337; // Adding elements.

	// Print out the size of the map after adding the above element.
	std::cout << "Map Size: " << myMap.size() << std::endl; // Output size.

	std::cout << "map['a'] = " << myMap['a'] << std::endl; // Access the element in the map.

	// Adds a bunch of random elements using the srand function we called earlier on using a for loop.
	for (count = 0; count < 10; count++)
	{
		myMap[char(rand() % 93 + 33)] = rand();
	}

	// Find all the elements in the map using a for loop.
	std::cout << std::endl << "Elements in Map:" << std::endl;
	for (count = 33; count < 126; count++)
	{
		if (myMap.count(char(count)) > 0) // Element exists
		{
			std::cout << char(count) << " : " << myMap[char(count)] << std::endl;
		}
	}

	system("pause");
	return 0;
}