/**
 * @file StarlinkBay.h
 * @class StarlinkBay
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Builder
 * Participant: Concrete Builder
 * 
 */
#ifndef STARLINKBAY_H
#define STARLINKBAY_H

#include "RocketshipBay.h"
#include "StarlinkCollection.h"
#include "Falcon9Factory.h"

class StarlinkBay : public RocketshipBay
{
public:
	/**
	 * @brief Constructs a new Starlink Bay
	 * 
	 */
	StarlinkBay();
	/**
	 * @brief Destroys the Starlink Bay
	 * 
	 */
	virtual ~StarlinkBay();
	/**
	 * @brief Get the Starlink collection object stored in starlink_collection
	 * 
	 * @return StarlinkCollection* 
	 */
	StarlinkCollection *getRocketship();
	/**
	 * @brief initialises the StarlinkCollection rocketship
	 * 
	 * @param n name of the rocketship
	 * @param BS base station the rocket is currently attached to
	 * @param SS space station the rocketship can go too
	 */
	void setName(string n, BaseStation* BS ,SpaceStation* SS=0);
	/**
	 * @brief builds the Rocket part of the rocketship. In this case a Falcon9 rocket will be constructed.
	 * 
	 */
	void buildRocket();
	/**
	 * @brief Not implemented for this class
	 * 
	 */
	void buildBody();
	/**
	 * @brief Adds the Starlink satellites to the Starlink collection using the satellite manager
	 * 
	 */
	void addCargo();

private:
	/**
	 * @brief Holds a pointer to the Dragon rocketship that is being created.
	 * 
	 */
	StarlinkCollection *starlink_collection;
	/**
	 * @brief Holds a pointer to the factory that creates a specific rocket.
	 * 
	 */
	RocketFactory *falcon9_factory;
};

#endif