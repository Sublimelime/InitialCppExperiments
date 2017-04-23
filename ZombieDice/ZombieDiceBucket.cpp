/*
 * ZombieDiceBucket.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: noah
 */

#include "ZombieDiceBucket.h"
#include "ZombieDie.h"
#include "GreenZombieDie.h"
#include "YellowZombieDie.h"
#include "RedZombieDie.h"
#include <vector>
#include <cstdlib>
#include <memory>

void ZombieDiceBucket::loadBucket() {
	//Clears dice and then loads 6 green dice, 4 yellow dice and 3 red dice.
	dice.clear();

	dice.push_back(std::unique_ptr<RedZombieDie>());
	dice.push_back(std::unique_ptr<RedZombieDie>());
	dice.push_back(std::unique_ptr<RedZombieDie>());

	dice.push_back(std::unique_ptr<GreenZombieDie>());
	dice.push_back(std::unique_ptr<GreenZombieDie>());
	dice.push_back(std::unique_ptr<GreenZombieDie>());
	dice.push_back(std::unique_ptr<GreenZombieDie>());
	dice.push_back(std::unique_ptr<GreenZombieDie>());
	dice.push_back(std::unique_ptr<GreenZombieDie>());

	dice.push_back(std::unique_ptr<YellowZombieDie>());
	dice.push_back(std::unique_ptr<YellowZombieDie>());
	dice.push_back(std::unique_ptr<YellowZombieDie>());
	dice.push_back(std::unique_ptr<YellowZombieDie>());
}

//removes and returns a random die from the bucket, throws -1(int) if bucket is empty.
std::unique_ptr<ZombieDie>& ZombieDiceBucket::draw() {
	int randIndex = (rand() % dice.size());
	std::unique_ptr<ZombieDie>& toRemove = dice.at(randIndex);
	dice.erase(dice.begin() + randIndex);

	if (dice.size() != 0) {
		return toRemove;
	} else {
		throw -1;
	}
	//Removes and returns 1 random die or null when the bucket is empty.
}
