/*
 * Mainfile.cpp
 *
 *  Created on: Apr 21, 2017
 *      Author: othscs253
 */

#include "Mainfile.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


int main() {
	using namespace std;

	int numPlayers(-1);
	while (numPlayers < 2 || numPlayers > 5) {
		cout << "How many players?\n";
		cin >> numPlayers;
		checkCin();
	}

	vector<string> names(numPlayers);
	vector<int> scores(numPlayers);

	int counter { 0 };
	while (counter < numPlayers) { //get player names for all players
		cout << "Name of player " << counter << "?\n";
		cin >> names.at(counter);
		if (!checkCin()) {
			cout << "Bad name, try again.\n";
		} else {
			counter++;
		}
	}
	shuffle(names);




	return 0;
}

//finds the winner of the game.
std::string findWinner(const std::vector<std::string> &names,
		const std::vector<int> &scores) {
	int highestVal { 0 }, index { -1 };
	for (int i = 0; i < names.size(); i++) {
		if (scores[i] > highestVal) {
			highestVal = scores[i];
			index = i;
		}
	}
	if (index == -1 || highestVal < 100)
		return "";
	else
		return names[index];
}

//shuffles the array it receives
void shuffle(std::vector<std::string> &users) {
	using namespace std;
	string temp1;
	string temp2;
	for (int y = 0; y < 10; y++) {
		int random1 = (rand() % users.size());
		int random2 = (rand() % users.size());
		temp1 = users.at(random1);
		temp2 = users.at(random2);
		users.at(random1) = temp1.at(0);
		users.at(random2) = temp2.at(0);
	}
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
