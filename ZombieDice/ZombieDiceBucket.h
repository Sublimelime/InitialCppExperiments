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
#include <memory>

class ZombieDiceBucket {
public:
	std::vector<std::unique_ptr<ZombieDie>> dice;

	ZombieDiceBucket() {
		dice.resize(13);
		loadBucket();
	}

	void loadBucket();
	std::unique_ptr<ZombieDie>& draw();

};

#endif /* ZOMBIEDICEBUCKET_H_ */
