/**
 * @file CrewDragonRocketship.h
 * @class CrewDragonRocketship
 * @author {Xander Coetzer, James Butler}
 * @brief 
 * Design Pattern: Builder
 * Participant: Product
 * 
 */
#ifndef CREWDRAGONROCKETSHIP_H
#define CREWDRAGONROCKETSHIP_H

using namespace std;

#include <iostream>
#include "Rocketship.h"
#include "Cargo.h"
#include "Spacecraft.h"

class CrewDragonRocketship : public Rocketship
{
public:
    /**
     * @brief Construct a new Crew Dragon Rocketship object
     * 
     * @param n Name of the rocketship
     */
    CrewDragonRocketship(string n);
    /**
     * @brief Destroy the CrewDragon Rocketship
     * 
     */
    virtual ~CrewDragonRocketship();
    /**
     * @brief Launches the CrewDragon rocketship into space and attaches it to the space station
     * 
     * @param ss The space station that the rocket gets attached to
     */
    void Launch(Station* ss);
    /**
     * @brief Creates a deep copy of the CrewDragon rocketship and returns it
     * 
     * @return Rocketship* 
     */
    Rocketship *clone();
    /**
     * @brief Attaches a spacecraft to the CrewDragon rocketship
     * 
     * @param s The spacecraft to attach
     */
    void attachSpacecraft(Spacecraft *s);
    /**
     * @brief Attaches a rocket to the CrewDragon rocketship
     * 
     * @param r The rocket to attach
     */
    void attachRocket(FalconRocket *r);
    /**
     * @brief Attaches cargo to the CrewDragon rocketship
     * 
     * @param cvect A vector with all the cargo to be attached to the CrewDragon rocketship
     */
    void attachCargo(vector<Cargo *> cvect);
    /**
     * @brief Empties the cargo at the station that the CrewDragon rocketship is currently attached to
     * 
     * @return Cargo* 
     */
    void dropCargo();
    /**
     * @brief Gives a count of the engines on the CrewDragon rocketship
     * 
     * @return int 
     */
    virtual int getRockets();
    /**
     * @brief Returns if the engines are on or not
     * 
     * @return true 
     * @return false 
     */
    virtual bool testFire();
    /**
     * @brief Returns if cargo has been loaded or not
     * 
     * @return true 
     * @return false 
     */
    virtual bool testLoading();
    /**
     * @brief Prompts the loading of Cargo* and sends the rocket back to BaseStation
     * 
     */
    void startLanding(Station* base);
    /**
     * @brief Get the Spacecraft object
     * 
     * @return Spacecraft* 
     */
    Spacecraft* getSpacecraft();
    /**
     * @brief Get the Rocket object
     * 
     * @return FalconRocket* 
     */
    FalconRocket* getRocket();
    /**
     * @brief Get the Cargo object
     * 
     * @return Cargo** 
     */
    Cargo** getCargo();
private:
    /**
     * @brief An array of Cargo* that holds all the loaded cargo
     * 
     */
    Cargo **cargo;
    /**
     * @brief A pointer to the spacecraft that is attached to the CrewDragon rocketship.
     * 
     */
    Spacecraft *spacecraft;
    /**
     * @brief A pointer to the rocket that is attached to the rocketship 
     * 
     */
    FalconRocket *rocket;
};

#endif