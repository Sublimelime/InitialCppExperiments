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

int main() {
	using namespace std;
	int playerNum { 0 }, playerCount;

	do {
		cout << "How many players?\n";
		cin >> playerCount;
		if (cin.fail()) {
			cin.clear();
		}
		cin.ignore(2345567, '\n');
	} while (playerCount < 2 || playerCount > 5);
	string *playerNames = new string[playerCount];
	int *playerScores = new int[playerCount];

	int counter { 0 };
	while (counter < playerCount) { //get player names for all players
		cout << "Name of player " << counter << "?\n";
		cin >> playerNames[counter];
		if (cin.fail()) {
			cout << "Bad name, try again.\n";
			cin.clear();
		} else {
			counter++;
		}
		cin.ignore(2345567, '\n');
	}
	shuffle(playerNames, playerCount);

	while (true) { // game loop
		int turnScore = 0;
		bool turnContinue = true;
		string winner = findWinner(playerNames, playerCount, playerScores,
				playerCount);
		if (winner != "") {
			cout << "The winner is " << winner << "!\n";
			delete[] playerNames;
			delete[] playerScores;
			return 0;
		}
		while (turnContinue) {

			cout << "Player " << playerNames[playerNum] << "'s turn. ";
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
				playerScores[playerNum] += turnScore;
				turnContinue = false;
				break;
			}

		}
		playerNum = (playerNum + 1) % playerCount;
	}
	delete[] playerNames;
	delete[] playerScores;
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
std::string findWinner(std::string names[], int namesSize,
		int scores[],
		int scoresSize) {
	int highestVal { 0 }, index { -1 };
	for (int i = 0; i < namesSize; i++) {
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
void shuffle(std::string users[], int size) {
	using namespace std;
	string *temp1 = new string[1];
	string *temp2 = new string[1];
	for (int y = 0; y < 10; y++) {
		int random1 = (rand() % size);
		int random2 = (rand() % size);
		temp1[0] = users[random1];
		temp2[0] = users[random2];
		users[random1] = temp1[0];
		users[random2] = temp2[0];
	}
	delete[] temp1;
	delete[] temp2;
}
