/**
 * @file CreateDragon.h
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Builder
 * Participant: Concrete Builder
 * 
 */
#ifndef DRAGONBAY_H
#define DRAGONBAY_H

#include "RocketshipBay.h"
#include "DragonRocketship.h"
#include "DragonFactory.h"
#include "FalconHeavyFactory.h"

class DragonBay : public RocketshipBay
{
public:
	/**
	 * @brief Constructs a new Dragon Bay
	 * 
	 */
	DragonBay();
	/**
	 * @brief Destroys the Dragon Bay
	 * 
	 */
	virtual ~DragonBay();
	/**
	 * @brief Get the DragonRocketship object stored in dragon
	 * 
	 * @return DragonRocketship* 
	 */
	DragonRocketship *getRocketship();
	/**
	 * @brief initialises the Dragon rocketship
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
	 * @brief Builds the spaceship of the rocketship. In this case a Dragon spacecraft will be constructed.
	 * 
	 */
	void buildBody();
	/**
	 * @brief Adds Cargo to the rocketship. In this case only equipment can be loaded.
	 * 
	 */
	void addCargo();

private:
	/**
	 * @brief Holds a pointer to the Dragon rocketship that is being created.
	 * 
	 */
	DragonRocketship *dragon;
	/**
	 * @brief Holds a pointer to the factory that creates a specific rocket.
	 * 
	 */
	RocketFactory *falconheavy_factory;
	/**
	 * @brief Holds a pointer to the factory that creates a specific spacecrafts.
	 * 
	 */
	SpacecraftFactory *dragon_factory;
};

#endif