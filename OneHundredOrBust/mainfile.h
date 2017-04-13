/*
 * mainfile.h
 *
 *  Created on: Apr 13, 2017
 *      Author: othscs253
 */

#ifndef MAINFILE_H_
#define MAINFILE_H_

//returns a random int between 1-6
int rollDie();

/**
 * Receives two arrays, returns a string containing the name of the winning player
 * or null if there is no winner yet.
 */
std::string findWinner(const std::string names[], const int scores[]);

//shuffles the array it receives
void shuffle(std::string users[]);

#endif /* MAINFILE_H_ */
