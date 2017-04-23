/*
 * ZombieDie.h
 *
 *  Created on: Apr 22, 2017
 *      Author: noah
 */

#ifndef ZOMBIEDIE_H_
#define ZOMBIEDIE_H_

enum class DieRoll {
	NOT_ROLLED, RUNNER, BRAIN, SHOT,
};

enum class DieColor {
	RED, GREEN, YELLOW,
};

class ZombieDie {
protected:
	DieColor dieColor;
	DieRoll value { DieRoll::NOT_ROLLED };
public:
	ZombieDie() {
	}

	virtual ~ZombieDie() {

	}

	DieRoll getValue() {
		return value;
	}

	DieColor getDieColor() const {
		return dieColor;
	}

	void setDieColor(DieColor dieColor) {
		this->dieColor = dieColor;
	}

	virtual void roll();
};

#endif /* ZOMBIEDIE_H_ */
