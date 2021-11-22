/**
 * @file Rocketship.h
 * @author {Xander Coetzer, James Butler}
 * @brief 
 * 
 * Design Patterns: Builder
 * Participant: Product
 */
#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

using namespace std;
#include <iostream>
#include <string>
//#include <unistd.h>
#include "Station.h"
#include "FalconRocket.h"

class Rocketship
{
public:
	/**
	 * @brief Construct a new Rocketship object
	 * 
	 * @param n Name of the rocketship
	 * @param t Type of rocketship
	 */
	Rocketship(string n, char t);

	/**
	 * @brief Destroy the Rocketship object
	 * 
	 */
	virtual ~Rocketship();

	/**
	 * @brief Launches the rocket into space and attaches it to the space station
	 * 
	 * @param ss The space station that the rocket is being launched to
	 */
	virtual void Launch(Station* ss) = 0;

	/**
	 * @brief Creates a deep copy of the rocketship and returns it
	 * 
	 * @return Rocketship* 
	 */
	virtual Rocketship *clone() = 0;

	/**
	 * @brief Return name of the rocketship
	 * 
	 * @return string 
	 */
	string getName();

	/**
	 * @brief Starts the countdown before launch
	 * 
	 */
	void countdown();

	/**
	 * @brief Returns the type of the rocket(DragonRocketship, CrewDragonRocketship or StarlinkCollection)
	 * 
	 * @return char 
	 */
	char getType();

	/**
	 * @brief Attaches the specific rocketship to a base or space station
	 * 
	 * @param s The station to attach to
	 */
	void attachToStation(Station *s);

	/**
	 * @brief Returns the station that the rocketship is currently attached to
	 * 
	 * @return Station* 
	 */
	Station *getStation();

	/**
	 * @brief Gives a count of the engines on this rocketship setup
	 * 
	 * @return int 
	 */
	virtual int getRockets() = 0;

	/**
	 * @brief Returns if the engines are on or not
	 * 
	 * @return true 
	 * @return false 
	 */
	virtual bool testFire() = 0;

	/**
	 * @brief Returns if cargo has been loaded or not
	 * 
	 * @return true 
	 * @return false 
	 */
	virtual bool testLoading() = 0;

private:
	/**
	 * @brief The name of the rocketship
	 * 
	 */
	string name;

	/**
	 * @brief The type of the rocketship
	 * (DragonRocketship, CrewDragonRocketship or StarlinkCollection)
	 * d or c or s
	 * 
	 */
	char rocketshipType;
	
	/**
	 * @brief The station that the rocketship is currently attached to
	 * 
	 */
	Station *current_Station;
};

#endif