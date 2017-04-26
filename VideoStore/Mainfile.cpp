/*
 * Mainfile.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#include "Game.h"
#include "Video.h"
#include <iostream>
#include <string>
#include <vector>
#include "VideoStore.h"

int main() {
	using namespace std;
	vector<Rental*> rentals;
	rentals.push_back(new Game("Overwatch", 40, GameRating::TEEN, "PC", 1));
	rentals.push_back(
			new Game("Team Fortress 2", 0, GameRating::MATURE, "PC", 6));
	rentals.push_back(
			new Game("Tic Tac Toe", 0, GameRating::EVERYONE, "Board", 2));
	rentals.push_back(new Game("Connect 4", 10, GameRating::EVERYONE, "PC", 2));

	vector<string> actors { "Frank", "Joe", "Bill" };
	rentals.push_back(
			new Video("SpongeBob", 10, VideoRating::G,
					"Who lives in a pineapple under the sea", actors,
					"Michal Bay", 200));

	VideoStore videoStore(rentals);
	deallocateVector(rentals);
	return 0;
}

//deallocates the vector of pointers sent to it.
template<typename T>
void deallocateVector(std::vector<T*>& vect) {
	for (int i = 0; i < vect.size(); i++) {
		delete vect.at(i);
	}
}
