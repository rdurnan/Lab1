// Lab1.cpp
// Ryan Durnan
// COSC-1030-01
// Lab1
// 17 Sept 2018
/*   
   This program shall open and read a .txt file
   filled with numbers. Once the file is open, 
   it will report the count of total numbers, 
   the first two numbers, and the last two numbers.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::cerr;
using std::ifstream;
using std::string;

int main()
{
	string name;
	ifstream iFile;
	int count=0;
	double temp;
	double first;
	double second;
	double current;
	double previous;

	cout << "Enter a valid file name: ";					// Prompt the user to enter a file name.
	getline(cin, name);										// Get the file name from the user.
	iFile.open(name);										// Attempt to open user's file.
	
	while (!iFile) {										// If the user's file name is invalid...
		cerr << "Cannot open file: " << name;
		iFile.close();										// ...make sure file is close (just in case something was opened...
		iFile.clear();										// ...make sure the stream is clear... 
		cout << "\nEnter another file name: ";
		getline(cin, name);									// ...get another file name...
		iFile.open(name);									// ...attempt to open user's file again.
	}

	if (iFile.is_open()) {
		while (!iFile.eof()) {
			iFile >> temp;									// Get the next number in the file.
			if (!iFile.fail()) {
				switch (count) {
				case 0:										// On the first input...
					first = temp;							// ...put that value in its own variable...
					current = temp;							// ...be sure to track the current value...
					count++;								// ...increment the count.
					break;
				case 1:										// On the second input...
					second = temp;							// ...put that value in its own variable...
					previous = current;						// ...be sure to track the previous value...
					current = temp;							// ...be sure to track the current value...
					count++;								// ...increment the count.
					break;
				default:									// For all subsequent inputs...
					previous = current;						// ...be sure to track the previous value...
					current = temp;							// ...be sure to track the current value...
					count++;								// ...increment the count.
				}
			}
		}
	}

	cout << "Total Count: " << count << endl;				// Display the total count of numbers.
	cout << "First Number: " << first << endl;				// Display the first number.
	cout << "Second Number: " << second << endl;			// Display the second number.
	cout << "Second-to-last Number: " << previous << endl;	// Display the second-to-last number.
	cout << "Last Number: " << current << endl;				// Display the last number.

	iFile.close();											// Close the file.

    return 0;
}

