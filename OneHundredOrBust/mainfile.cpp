/*
 * mainfile.cpp
 *
 *  Created on: Apr 13, 2017
 *      Author: othscs253
 */

#include "mainfile.h"
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>

int main() {
	using namespace std;
	while (true) {
		cout << "Player 1's turn. Choices:\n1. Roll dice\n";

	}
}

//returns a random int between 1-6
int rollDie() {
	return std::rand() % 6 +1;
}

/**
 * Receives two arrays, returns a string containing the name of the winning player
 * or null if there is no winner yet.
 */
std::string findWinner(const std::string names[], const int scores[]) {
	return "";
}

//shuffles the array it receives
void shuffle(std::string users[]) {

}
