/*
 * ZombieDiceBucket.h
 *
 *  Created on: Apr 22, 2017
 *      Author: noah
 */

#ifndef ZOMBIEDICEBUCKET_H_
#define ZOMBIEDICEBUCKET_H_

#include "ZombieDie.h"
#include <vector>
#include <string>

class ZombieDiceBucket {
public:
	static std::vector<ZombieDie> dice;

	ZombieDiceBucket() {
		dice.resize(13);
	}

	void loadBucket();
	ZombieDie draw();

};

#endif /* ZOMBIEDICEBUCKET_H_ */
