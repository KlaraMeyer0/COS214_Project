/**
 * @file CrewDragonBay.h
 * @class CrewDragonBay
 * @author Xander Coetzer
 * @brief
 * Design Pattern: Builder
 * Participant: Concrete Builder
 *
 */
#ifndef CREWDRAGONBAY_H
#define CREWDRAGONBAY_H

#include "RocketshipBay.h"
#include "CrewDragonRocketship.h"
#include "CrewDragonFactory.h"
#include "FalconHeavyFactory.h"

class CrewDragonBay : public RocketshipBay
{
public:
	/**
	 * @brief Constructs a new Crew Dragon Bay
	 *
	 */
	CrewDragonBay();
	/**
	 * @brief Destroys the Crew Dragon Bay
	 *
	 */
	virtual ~CrewDragonBay();
	/**
	 * @brief Get the CrewDragon Rocketship object stored in crew_dragon
	 *
	 * @return CrewDragonRocketship*
	 */
	CrewDragonRocketship *getRocketship();
	/**
	 * @brief initialises the CrewDragon rocketship
	 *
	 * @param n name of the rocketship
	 * @param bs base station the rocket is currently attached to
	 * @param sp space station the rocketship can go too
	 */
	void setName(string n, BaseStation *bs, SpaceStation *sp = nullptr);
	/**
	 * @brief Builds the Rocket part of the rocketship. In this case a FalconHeavy rocket will be constructed.
	 *
	 */
	void buildRocket();
	/**
	 * @brief Builds the spaceship of the rocketship. In this case a CrewDragon spacecraft will be constructed.
	 *
	 */
	void buildBody();
	/**
	 * @brief Adds Cargo to the rocketship. In this case both humans and equipment can be loaded.
	 *
	 */
	void addCargo();

private:
	/**
	 * @brief Holds a pointer to the CrewDragon rocketship that is being created.
	 *
	 */
	CrewDragonRocketship *crew_dragon;
	/**
	 * @brief Holds a pointer to the factory that creates a specific spacecrafts.
	 *
	 */
	SpacecraftFactory *crewdragon_factory;
	/**
	 * @brief Holds a pointer to the factory that creates a specific rocket.
	 *
	 */
	RocketFactory *falconheavy_factory;
};

#endif