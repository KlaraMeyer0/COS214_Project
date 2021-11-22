/**
 * @file DragonRocketship.h
 * @author {Xander Coetzer, James Butler}
 * @brief 
 * Design Pattern: Builder
 * Participant: Product
 * 
 */
#ifndef DRAGONROCKETSHIP_H
#define DRAGONROCKETSHIP_H

using namespace std;

#include "Rocketship.h"
#include "Equipment.h"
#include "DragonSpacecraft.h"

class DragonRocketship : public Rocketship
{
public:
    /**
     * @brief Constructs a new Dragon Rocketship
     * 
     * @param n 
     */
    DragonRocketship(string n);
    /**
     * @brief Destroys the Dragon Rocketship
     * 
     */
    virtual ~DragonRocketship();
    /**
     * @brief Launches the Dragon rocketship into space and attaches it to the space station
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
     * @brief Creates a deep copy of the Dragon rocketship and returns it
     * 
     * @param s 
     */
    void attachSpacecraft(Spacecraft *s);
    /**
     * @brief Attaches a rocket to the Dragon rocketship
     * 
     * @param r 
     */
    void attachRocket(FalconRocket *r);
    /**
     * @brief Attaches cargo to the Dragon rocketship
     * 
     * @param cvect A vector with all the cargo to be attached to the Dragon rocketship
     */
    void attachCargo(vector<Cargo*> cvect);
    /**
     * @brief Empties the cargo at the station that the Dragon rocketship is currently attached to
     * 
     * @return Cargo* 
     */
    void dropCargo();
    /**
     * @brief Gives a count of the engines on the Dragon rocketship
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
    void startLanding();
private:
    /**
     * @brief An array of Cargo* that holds all the loaded cargo
     * 
     */
    Cargo **cargo;
    /**
     * @brief A pointer to the spacecraft that is attached to the Dragon rocketship.
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