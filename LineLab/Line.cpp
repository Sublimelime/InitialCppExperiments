/*
 * Line.cpp
 *
 *  Created on: Apr 18, 2017
 *      Author: noah
 */

#include <string>
#include <iostream>
#include "Line.h"

std::string Line::print() {
	std::string print = "Line(P1:" + std::to_string(getPoint1X()) + ','
			+ std::to_string(getPoint1Y()) + " P2:"
			+ std::to_string(getPoint2X()) + ',' + std::to_string(getPoint2Y())
			+ ")\n";
	return print;
}
