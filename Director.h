/**
 * @file Director.h
 * @class Director
 * @author {James Butler,Xander Coetzer}
 * @brief Design Pattern: Command, Participant: Invoker
 */
#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Work.h"
#include "LaunchInterface.h"
#include "RocketshipEngineer.h"
#include "CreateCrewDragon.h"
#include "CreateDragon.h"
#include "CreateStarlink.h"
#include "Backup.h"
#include "TestLaunch.h"
#include "OrderCargo.h"

class Director
{
public:
    /**
     * @brief Construct a new Director object
     * 
     * @param i The launch interface to set
     * @param b The base station to set
     * @param s The space station to set
     */
    Director(LaunchInterface *i, BaseStation *b, SpaceStation* s);
    /**
     * @brief Destroy the Director object
     * 
     */
    virtual ~Director();
    /**
     * @brief Create and load a Falcon Heavy rocket with a Dragon spaceshuttle (Cargo)
     * 
     */
    void makeDragon();
    /**
     * @brief Create and load a Falcon Heavy rocket with a Dragon spaceshuttle (Crew)
     * 
     */
    void makeCrewDragon();
    /**
     * @brief Make a Starlink Collection and attach it to a Falcon9 rocket
     * 
     */
    void makeStarlink();
    /**
     * @brief Create a Backup of the current launch setup
     * 
     */
    void createBackup();
    /**
     * @brief Restores a saved setup for launching
     * 
     */
    void retrieveBackup();
    /**
     * @brief Launches a rocket or selection of rockets with or without tests
     * 
     */
    void startTestLaunch();
    /**
     * @brief Calls a rocketship back from a spacestation
     * 
     */
    void returnRocketship();
    /**
     * @brief Loads cargo from the rocketship to the space station
     * 
     */
    void receiveCargo();
    /**
     * @brief Runs a demonstration of the mediator pattern
     * 
     */
    void runMediator();

private:
    /**
     * @brief An array of the commands
     * 
     */
    Work **command;
    /**
     * @brief The launch interface that coordinates the launches
     * 
     */
    LaunchInterface *interface;
    /**
     * @brief The launch engineer that directs rocket construction
     * 
     */
    RocketshipEngineer *engineer;
    /**
     * @brief The bay to create Crew capable Falcon Heavy rocket setups
     * 
     */
    CrewDragonBay *crewdragon_Bay;
    /**
     * @brief The bay to create Falcon Heavy rocket setups
     * 
     */
    DragonBay *dragon_Bay;
    /**
     * @brief The bay to create Falcon9 rockets that launch satellites
     * 
     */
    StarlinkBay *starlink_Bay;
    /**
     * @brief The station on earth
     * 
     */
    BaseStation *base_station;
    /**
     * @brief The space station to transport crew and cargo to
     * 
     */
    SpaceStation *space_station;
};

#endif