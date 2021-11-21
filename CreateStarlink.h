/**
 * @file CreateDragon.h
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Command
 * Participant: Concrete Command
 * 
 */
#ifndef CREATESTARLINK_H
#define CREATESTARLINK_H

#include "Work.h"
#include "RocketshipEngineer.h"
#include "Station.h"

class CreateStarlink : public Work{
public:
	/**
	 * @brief Create a Starlink collection, which is a type of rocketship, and store it in the interface
	 * 
	 * @param e The RocketshipEngineer is used to create the Starlink collection
	 * @param l The receiver which receives the new Rocketship
	 * @param s Where the newly created Rocketship is retrieved from
	 * @param b The base station that the rocket gets launched from
	 * @param ss The space station that the satellites communicate with
	 */
	CreateStarlink(RocketshipEngineer *e, LaunchInterface *l, StarlinkBay *s, BaseStation *b, SpaceStation* ss);
	/**
	 * @brief Destroy the Create Starlink command
	 * 
	 */
	virtual ~CreateStarlink();
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
	 * @brief holds the launch interface to which all the rocketships will be added
	 * 
	 */
	LaunchInterface *launch_interface;
	/**
	 * @brief contains the rocketship created by the engineer
	 * 
	 */
	StarlinkBay *starlink_bay;
	/**
	 * @brief Holds a pointer to the base station from which the rocket is going to be launched
	 * 
	 */
	BaseStation* base_station;
	/**
	 * @brief Holds a pointer to the space station with which the satellites will communicate
	 * 
	 */
	SpaceStation* space_station;
};

#endif