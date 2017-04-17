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


std::string numberRange(int lower, int upper) {
	return "";
}

std::string letterRange(char lower, char upper) {
	return "";
}

int timeToMins(int hours, int minutes) {
	return 0;
}

std::string intToString(int integer) {
	return "";
}

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

