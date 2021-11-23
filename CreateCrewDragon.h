/**
 * @file CreateCrewDragon.h
 * @class CreateCrewDragon
 * @author Xander Coetzer
 * @brief Inherits from Work, Design Pattern: Command, Participant: Concrete Command
 */
#ifndef CREATECREWDRAGON_H
#define CREATECREWDRAGON_H

#include "Work.h"
#include "RocketshipEngineer.h"
#include "Station.h"

class CreateCrewDragon : public Work
{
public:
	/**
	 * @brief Create a Crew Dragon object and stores it into interface
	 *
	 * @param e The RocketshipEngineer is used to create the CrewDragonRocketship
	 * @param l The receiver which receives the new Rocketship
	 * @param cd Where the newly created Rocketship is retrieved from
	 * @param s The base station that the rocket gets launched from
	 */
	CreateCrewDragon(RocketshipEngineer *e, LaunchInterface *l, CrewDragonBay *cd, BaseStation *s);
	/**
	 * @brief Destroy the Create Crew Dragon object
	 *
	 */
	virtual ~CreateCrewDragon();
	/**
	 * @brief The creation process for the CrewDragonRocketship
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
	CrewDragonBay *crewdragon_bay;
	/**
	 * @brief Holds a pointer to the base station from which the rocket is going to be launched
	 *
	 */
	BaseStation *base_station;
};

#endif