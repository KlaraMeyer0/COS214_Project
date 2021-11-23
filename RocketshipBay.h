/**
 * @file RocketshipBay.h
 * @class RocketshipBay
 * @author Xander Coetzer
 * @brief
 * Design Pattern: Builder
 * Participant: Builder
 *
 */
#ifndef ROCKETSHIPBAY_H
#define ROCKETSHIPBAY_H

using namespace std;
#include <string>
#include "BaseStation.h"
#include "SpaceStation.h"

class RocketshipBay
{
public:
	/**
	 * @brief initialises the specefic rocketship
	 *
	 * @param n name of the rocketship
	 * @param BS base station the rocket is currently attached to
	 * @param SS space station the rocketship can go too
	 */
	virtual void setName(string n, BaseStation *BS, SpaceStation *SS = nullptr) = 0;
	/**
	 * @brief Builds the Rocket part of the rocketship.
	 *
	 */
	virtual void buildRocket() = 0;
	/**
	 * @brief Builds the spaceship of the rocketship if it exists
	 *
	 */
	virtual void buildBody() = 0;
	/**
	 * @brief Attaches products that has to be taken too and from space
	 *
	 */
	virtual void addCargo() = 0;
};

#endif