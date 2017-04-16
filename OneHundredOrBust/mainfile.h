/*
 * mainfile.h
 *
 *  Created on: Apr 13, 2017
 *      Author: othscs253
 */

#ifndef MAINFILE_H_
#define MAINFILE_H_

#include <string>
#include <vector>

//returns a random int between 1-6
int rollDie();

/**
 * Receives two arrays, returns a string containing the name of the winning player
 * or null if there is no winner yet.
 */
std::string findWinner(std::vector<std::string> names, std::vector<int> scores);

//shuffles the array it receives
void shuffle(std::vector<std::string> users);

#endif /* MAINFILE_H_ */
