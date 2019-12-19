// Ryan Bachman
// CSC383 - Data Structures and Algorithms
// University of Advancing Technology
// Project: Sorting

/* 
* Implementation
* Code/Implement a sorting algorithms of your choice (for example, insertion sort, merge sort, quick sort) that operates 
* on your Linked List data structure. 
*
* For testing, your program should accept an array of integers with a minimum of 20 integers OR your program could take 
* two arguments, the filename of a data file, and an integer that defines the algorithm that will be used to sort.
*
* The data file contains one integer per line, for an unknown number of lines.  Your program should parse this data file 
* into your linked list structure, and then use the specified algorithm to sort the array.  Your program should time how 
* long it takes to sort the data, and report that information to the console in seconds.  Take care to only report the time it 
* takes to sort, not perform file i/o.  For small dataset sizes, you may have to average several consecutive sorts in order to 
* arrive at a valid timing measurement.
*
* HINT: Use the “clock()” - system call: http://www.cplusplus.com/reference/clibrary/ctime/clock/
*
* If the size of the dataset is less than 100, your program should print the sorted list to the console screen.
*
* In Files, there is a file called “SortDatasets.zip” containing several datasets.  For each dataset in the file, run each 
* sorting algorithm, and record the times in an Excel table.  
*
* Once all of your data is collected, graph the performance of each algorithm by data set size, and use a trend-line to 
* determine the growth-rate of each algorithm. */

 // Templated add functions will do the function no matter what the data type.
 // Will need current and previous pointers so we can move backwards if need be. Previous will always be one node behind.

 // Preprocessor Directives
#include <iostream>
#include <memory>
#include "Interface.h"

using namespace std;

// Main function begins.
int main()
{
	// Call the menu function.
	Interface();

	system("pause"); // So it stops before quitting out.
	return 0;

} // End of main function.