/*
 * RedZombieDie.h
 *
 *  Created on: Apr 22, 2017
 *      Author: noah
 */

#ifndef REDZOMBIEDIE_H_
#define REDZOMBIEDIE_H_

#include "ZombieDie.h"
#include <cstdlib>
#include <iostream>

class RedZombieDie: public ZombieDie {
public:
	RedZombieDie() {
		dieColor = DieColor::RED;
	}

	virtual ~RedZombieDie() {

	}

	virtual void roll() override final {
		int randomRoll((rand() % 6) + 1);
		switch (randomRoll) {
		case 1:
		case 2:
			value = DieRoll::RUNNER;
			break;
		case 3:
			value = DieRoll::BRAIN;
			break;
		case 4:
		case 5:
		case 6:
			value = DieRoll::SHOT;
			break;
		default:
			std::cout << "Unknown value rolled on a red die: " << randomRoll
					<< "\n";
		}
	}
};

#endif /* REDZOMBIEDIE_H_ */
