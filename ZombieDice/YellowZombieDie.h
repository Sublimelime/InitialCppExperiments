/*
 * YellowZombieDie.h
 *
 *  Created on: Apr 22, 2017
 *      Author: noah
 */

#ifndef YELLOWZOMBIEDIE_H_
#define YELLOWZOMBIEDIE_H_

#include "ZombieDie.h"
#include <cstdlib>
#include <iostream>

class YellowZombieDie: public ZombieDie {
public:
	YellowZombieDie() {
		dieColor = DieColor::YELLOW;
	}

	virtual ~YellowZombieDie() {

	}

	virtual void roll() override final {
		int randomRoll((rand() % 6) + 1);
		switch (randomRoll) {
		case 1:
		case 2:
			value = DieRoll::RUNNER;
			break;
		case 3:
		case 4:
			value = DieRoll::BRAIN;
			break;
		case 5:
		case 6:
			value = DieRoll::SHOT;
			break;
		default:
			std::cout << "Unknown value rolled on a yellow die: " << randomRoll
					<< "\n";
		}
	}
};

#endif /* YELLOWZOMBIEDIE_H_ */
