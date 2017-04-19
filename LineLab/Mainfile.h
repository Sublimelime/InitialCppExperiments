/*
 * Mainfile.h
 *
 *  Created on: Apr 18, 2017
 *      Author: othscs253
 */

#ifndef MAINFILE_H_
#define MAINFILE_H_

#include <string>
#include "Line.h"


bool checkCin();

std::string viewIntersect(Line &ln1, Line &ln2);

void changeLine(Line &line);

void changePoint1(Line &line);

void changePoint2(Line &line);

#endif /* MAINFILE_H_ */
