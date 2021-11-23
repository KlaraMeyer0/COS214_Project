/**
 * @file CreateDragon.h
 * @class CreateDragon
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Command
 * Participant: Concrete Command
 * 
 */

#ifndef CREATEDRAGON_H
#define CREATEDRAGON_H

#include "Work.h"
#include "RocketshipEngineer.h"
#include "Station.h"

class CreateDragon : public Work {
public:
	/**
	 * @brief Create a Dragon object and stores it in the interface
	 * 
	 * @param e The RocketshipEngineer is used to create the DragonRocketship
	 * @param l The receiver which receives the new Rocketship
	 * @param d Where the newly created Rocketship is retrieved from
	 * @param s The base station that the rocket gets launched from
	 */
	CreateDragon(RocketshipEngineer *e, LaunchInterface *l, DragonBay *d, BaseStation *s);
	/**
	 * @brief Destroy the Create Dragon object
	 * 
	 */
	virtual ~CreateDragon();
	/**
	 * @brief The creation process for the DragonRocketship
	 * 
	 */
	void execute();
	/**
	 * @brief Method not required for this class
	 * 
	 */
	void undo();
private:
	/**
	 * @brief holds the passed in engineer pointer
	 *
	 */
	RocketshipEngineer *engineer;
	/**
	 * @brief contains the rocketship created by the engineer
	 *
	 */
	DragonBay *dragon_bay;
	/**
	 * @brief Holds a pointer to the base station from which the rocket is going to be launched
	 * 
	 */
	BaseStation* base_station;
};

#endif