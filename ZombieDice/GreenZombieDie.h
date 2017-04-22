/*
 * GreenZombieDie.h
 *
 *  Created on: Apr 22, 2017
 *      Author: noah
 */

#ifndef GREENZOMBIEDIE_H_
#define GREENZOMBIEDIE_H_

#include "ZombieDie.h"
#include <cstdlib>
#include <iostream>

class GreenZombieDie: public ZombieDie {
public:
	GreenZombieDie() {
		dieColor = DieColor::GREEN;
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
		case 5:
			value = DieRoll::BRAIN;
			break;
		case 6:
			value = DieRoll::SHOT;
			break;
		default:
			std::cout << "Unknown value rolled on a green die: " << randomRoll
					<< "\n";
		}
	}
};

#endif /* GREENZOMBIEDIE_H_ */
