/*
 * mainfile.h
 *
 *  Created on: Apr 13, 2017
 *      Author: othscs253
 */

#ifndef MAINFILE_H_
#define MAINFILE_H_

#include <string>

//returns a random int between 1-6
int rollDie();

/**
 * Receives two arrays, returns a string containing the name of the winning player
 * or null if there is no winner yet.
 */
std::string findWinner(std::string names[], int namesSize, int scores[],
		int scoresSize);

//shuffles the array it receives
void shuffle(std::string users[], int size);

#endif /* MAINFILE_H_ */
