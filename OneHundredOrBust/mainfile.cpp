/*
 * mainfile.cpp
 *
 *  Created on: Apr 13, 2017
 *      Author: othscs253
 */

#include "mainfile.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main() {
	using namespace std;
	int playerNum { 0 }, playerCount { 0 };

	do {
		cout << "How many players?\n";
		cin >> playerCount;
		if (cin.fail()) {
			cin.clear();
		}
		cin.ignore(2345567, '\n');
	} while (playerCount < 2 || playerCount > 5);
	vector<string> playerNames(playerCount);
	vector<int> playerScores(playerCount);

	int counter { 0 };
	while (counter < playerCount) { //get player names for all players
		cout << "Name of player " << counter << "?\n";
		cin >> playerNames.at(counter);
		if (cin.fail()) {
			cout << "Bad name, try again.\n";
			cin.clear();
		} else {
			counter++;
		}
		cin.ignore(2345567, '\n');
	}
	shuffle(playerNames);

	while (true) { // game loop
		int turnScore = 0;
		bool turnContinue = true;
		string winner = findWinner(playerNames, playerScores);
		if (winner != "") {
			cout << "The winner is " << winner << "!\n";
			return 0;
		}
		while (turnContinue) {

			cout << "Player " << playerNames.at(playerNum) << "'s turn. ";
			cout << "Choices:\n1. Roll dice\n2.Conclude turn\n";
			int choice;
			//cin.ignore(2345567, '\n');
			cin >> choice;
			if (cin.fail() || choice > 2 || choice < 1) {
				cout << "Bad choice, try again.\n";
				cin.clear();
				continue;
			}

			switch (choice) {
			case 1:
				{
				int dice1 = rollDie();
				int dice2 = rollDie();
				if (dice1 == dice2) {
					cout << "Doubles rolled. RIP.\n";
					turnScore = 0;
					turnContinue = false;
					continue;
				} else {
					cout << "A " << dice1 << " and a " << dice2
							<< " were rolled.\n";
					turnScore += dice1 + dice2;
				}
				break;
			}
			case 2:
				cout << "Stopping turn. Final score for turn is " << turnScore
						<< endl;
				playerScores.at(playerNum) += turnScore;
				turnContinue = false;
				break;
			}

		}
		playerNum = (playerNum + 1) % playerCount;
	}
	return 0;
}

//returns a random int between 1-6
int rollDie() {
	return std::rand() % 6 + 1;
}

/**
 * Receives two arrays, returns a string containing the name of the winning player
 * or null if there is no winner yet.
 */
std::string findWinner(std::vector<std::string> names,
		std::vector<int> scores) {
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
void shuffle(std::vector<std::string> users) {
	using namespace std;
	vector<string> temp1(1);
	vector<string> temp2(1);
	for (int y = 0; y < 10; y++) {
		int random1 = (rand() % users.size());
		int random2 = (rand() % users.size());
		temp1.at(0) = users.at(random1);
		temp2.at(0) = users.at(random2);
		users.at(random1) = temp1.at(0);
		users.at(random2) = temp2.at(0);
	}
}
