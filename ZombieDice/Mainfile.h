/*
 * Mainfile.h
 *
 *  Created on: Apr 21, 2017
 *      Author: othscs253
 */

#ifndef MAINFILE_H_
#define MAINFILE_H_

#include <vector>
#include <string>

void shuffle(std::vector<std::string> &users);
bool checkCin();
std::string findWinner(const std::vector<std::string> &names,
		const std::vector<int> &scores);

#endif /* MAINFILE_H_ */
