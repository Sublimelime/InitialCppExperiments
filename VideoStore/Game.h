/*
 * Game.h
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <iostream>

#include "Rental.h"

class Game: public Rental {

	std::string platform, director;
	int numberOfPlayers;

public:
	Game(std::string title, double cost, GameRating rating,
			std::string platform,
			int numberOfPlayers) :
			Rental(title, cost, rating), platform(platform), numberOfPlayers(
					numberOfPlayers) {

	}

};

#endif /* GAME_H_ */
