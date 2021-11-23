/**
 * @file RocketshipEngineer.h
 * @class RocketshipEngineer
 * @author Xander Coetzer
 * @brief Design Pattern: Builder, Participant: Director
 * 
 */
#ifndef ROCKETSHIPENGINEER_H
#define ROCKETSHIPENGINEER_H

#include "StarlinkBay.h"
#include "DragonBay.h"
#include "CrewDragonBay.h"

class RocketshipEngineer
{
public:
	/**
	 * @brief Construct a new Rocketship Engineer
	 * 
	 * @param cd The CrewDragon bay that is added to the array of bays in the Rocketship engineer
	 * @param d The Dragon bay that is added to the array of bays in the Rocketship engineer
	 * @param s The Starlink bay that is added to the array of bays in the Rocketship engineer
	 */
	RocketshipEngineer(CrewDragonBay *cd, DragonBay *d, StarlinkBay *s);
	/**
	 * @brief Destroy the Rocketship Engineer
	 * 
	 */
	virtual ~RocketshipEngineer();
	/**
	 * @brief Constructs a specific rocketship according to the bay input by calling that bay's functions
	 * 
	 * @param bay The bay in which has to be used for rocket construction
	 * @param name The name of the rocketship to be constructed
	 * @param bs The basestation at which the rocketship is constructed
	 * @param ss The spacestation that the rocketship communicates with (Can be null because only Starlink collection communicates with a spaces tation)
	 */
	void construct(int bay, string name, BaseStation *bs, SpaceStation* ss = nullptr);

private:
	/**
	 * @brief An array of all the rocketship bays used for holding the rockets after construction.
	 * 
	 */
	RocketshipBay **rb;
};

#endif