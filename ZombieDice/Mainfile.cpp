/*
 * Mainfile.cpp
 *
 *  Created on: Apr 21, 2017
 *      Author: othscs253
 */

#include "Mainfile.h"
#include "ZombieDiceBucket.h"
#include "ZombieDie.h"

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

	ZombieDiceBucket zdb;
	zdb.loadBucket();
	vector<ZombieDie> rolledDice; //the rolled dice array, holds all the dice that are on the figurative "table"
	vector<ZombieDie> runners;
	vector<ZombieDie> shots;
	vector<ZombieDie> brains;

	while (true) {

		for (int i = 0; i < numPlayers; i++) { //turn incrementer

			int tempBrains = 0; //points to be added to the player at end of turn.
			bool turnSuccess = false;

			//clear all arrayLists after turn.
			runners.clear();
			shots.clear();
			rolledDice.clear();
			brains.clear();
			zdb.loadBucket();
			while (!turnSuccess) { //while loop will exit at the end of player's turn, if appropriate action was taken.
				zdb.loadBucket();

				cout << "Total brains accumulated: " << tempBrains << "\n";
				cout << "Player " << names.at(i)
						<< ", Would you like to roll(0), or stop(1)?\n";
				int choice;
				cin >> choice;

				switch (choice) {
				case 0: //roll die, and add points to player score.

					//gather dice
					if (runners.size() > 0) {
						rerollDice(rolledDice, runners); //reroll dice in runners

					} else {
						if (zdb.draw()) //if dice bucket is not empty
							while (rolledDice.size() < 3) {
								rolledDice.push_back(zdb.draw());
							}
					}
					//check what the rolled values are.
					for (ZombieDie aRolledDice : rolledDice)
						aRolledDice.roll(); //roll all dice

					for (int p = 0; p < rolledDice.size(); p++) {
						switch (rolledDice.at(p).getValue()) {
						case DieRoll::BRAIN: //value 2
							//todo get actual value to add
							rolledDice.erase(rolledDice.begin() + p);
							//brains.push_back();
							p--;
							tempBrains = brains.size();
							break;
						case DieRoll::SHOT: //value 3
							shots.push_back(rolledDice.remove(p)); //transfer die from rolledDice to shots
							p--;
							if (shots.size() >= 3) { //if 3 shots have accumulated
								tempBrains = 0;
								brains.clear();
								turnSuccess = true;
								cout << "\n\n\n\nIt seems you got shot 3 times,"
										<< "ending your turn. Sorry mate.\n";
							}
							break;
						case DieRoll::RUNNER: //value 1
							runners.push_back(rolledDice.remove(p)); //add rolled runner to runner arrayList
							p--;
							break;
						}
					}
					cout << "Turn Summary:\n";
					cout << "Runners:" << runners << '\n';
					cout << "Brains:" << brains << '\n';
					cout << "Shots:" << shots << 'n';

					break;
				case 1: //exit and keep points.
					scores.at(i) += tempBrains;
					turnSuccess = true;
					break;
				case 3: //secret cheat to view scores of current player
					cout << "Player " << names.at(i) << " has a score of "
							<< scores.at(i) << '\n';
					break;
				default:
					cout << "Invalid choice. Please enter a 0 or 1.\n";
					break;
				}
			}
			findWinner(names, scores); //call findWinner to find the winner and end the program.
		}
	}

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
