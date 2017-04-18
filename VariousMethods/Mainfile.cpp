/*
 * Mainfile.cpp
 *
 *  Created on: Apr 17, 2017
 *      Author: othscs253
 */

#include <string>
#include "Mainfile.h"
#include <iostream>


int main() {
	using namespace std;
	while (true) {
		cout << "Please pick a choice.\n";
		cout << "1. Number range\n";
		cout << "2. Letter range\n";
		cout << "3. Time to minutes\n";
		cout << "4. Int to string\n";
		cout << "5. Favorites\n";
		int choice;
		cin >> choice;
		if (!checkCin()) {
			continue;
		}

		switch (choice) {
		case 1: {
			int lower, upper;
			cout << "First int?\n";
			cin >> lower;
			if (!checkCin()) {
				continue;
			}
			cout << "Second int?\n";
			cin >> upper;
			if (!checkCin()) {
				continue;
			}
			cout << numberRange(lower, upper);
		}
			break;
		case 2: {
			char lower, upper;
			cout << "First char?\n";
			cin >> lower;
			if (!checkCin()) {
				continue;
			}
			cout << "Second char?\n";
			cin >> upper;
			if (!checkCin()) {
				continue;
			}
			cout << letterRange(lower, upper);
		}
			break;
		case 3: {
			int hours, mins;
			cout << "How many hours?\n";
			cin >> hours;
			if (!checkCin()) {
				continue;
			}
			cout << "Mins?\n";
			cin >> mins;
			if (!checkCin()) {
				continue;
			}
			cout << "There are " << timeToMins(hours, mins) << " mins in "
					<< hours << " hours and " << mins << " minutes.\n";
		}
			break;
		case 4: {
			int integer;
			cout << "Integer?\n";
			cin >> integer;
			if (!checkCin()) {
				continue;
			}
			cout << "In string form, it is " << intToString(integer) << '\n';
		}
			break;
		case 5:
			favorites();
			break;
		default:
			cout << "Invalid choice.\n";
			break;
		}
	}
	return 0;
}

//Returns a String containing the numbers from the starting int to the ending int
std::string numberRange(int lower, int upper) {
	using namespace std;
	string finalString { };
	for (int i = lower; i < upper; i++) {
		finalString += i;
	}
	return finalString;
}

//Returns a String containing the letters from the starting letter to the ending letter
std::string letterRange(char lower, char upper) {
	char alphabet[] { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z' };
	std::string finalString { };
	int indexOfLower { -1 }, indexOfUpper { -1 };

	//find the indexes of both
	for (int i = 0; i < sizeof(alphabet) / sizeof(alphabet[0]); i++) {
		if(alphabet[i] == lower) {
			indexOfLower = i;
		} else if (alphabet[i] == upper) {
			indexOfUpper = i;
		}
	}
	if (indexOfLower == -1 || indexOfUpper == -1) { //check for invalid input
		return "Cannot find char in alphabet.\n";
	} else if (indexOfUpper < indexOfLower) {
		return "Second letter comes before first.\n";
	}

	//build final string
	for (int k = indexOfLower; k < indexOfUpper; k++) {
		finalString += alphabet[k];
	}

	return finalString;
}

//Returns an int, the number of minutes in the given time
int timeToMins(int hours, int minutes) {
	return 0;
}

//Returns a String, the text version of the number
std::string intToString(int integer) {
	return "";
}

//The method will print the maker’s favorite food, game, movie, song & sport
void favorites() {

}

//checks if input was valid, and clears it out
bool checkCin() {
	using namespace std;
	if (cin.fail()) {
		cin.clear();
		cout << "Invalid input.\n";
		cin.ignore(12344557, '\n');
		return false;
	}
	cin.ignore(12344557, '\n');
	return true;
}

