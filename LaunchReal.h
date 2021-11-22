/**
 * @file LaunchReal.h
 * @author James Butler
 * @brief 
 * 
 * Design Pattern: Decorator
 * Participant: Concrete Component
 */
#ifndef LAUNCHREAL_H
#define LAUNCHREAL_H

#include "Rocketship.h"
#include "Launch.h"

using namespace std;

class LaunchReal : public Launch{
public:
    /**
     * @brief Construct a new Launch Real object
     * 
     * @param r The rocketship to launch
     * @param s The spacestation to which the rocket is being launched to
     */
	LaunchReal(Rocketship* r,Station* s);

    /**
     * @brief Destroy the Launch Real object
     * 
     */
	virtual ~LaunchReal();

    /**
     * @brief Launch the stored rocketship
     * 
     */
    virtual void startLaunch();

    /**
     * @brief Get the Ship object
     * 
     * @return Rocketship* 
     */
    virtual Rocketship* getShip();
private:
    /**
     * @brief The rocketship to launch
     * 
     */
    Rocketship* ship;
    /**
     * @brief The space station to launch the rocketship to
     * 
     */
    Station* space_station;
};

#endif