/**
 * @file Launch.h
 * @author James Butler
 * @class Launch
 * @brief Design Pattern: Decorator, Participant: Component
 */
#ifndef LAUNCH_H
#define LAUNCH_H

#include "Rocketship.h"

using namespace std;

class Launch {
public:
	/**
	 * @brief Starts the launch of the rocket and all tests leading up to it
	 * 
	 */
	virtual void startLaunch() = 0;

	/**
	 * @brief Get the Ship object
	 * 
	 * @return Rocketship* 
	 */
	virtual Rocketship* getShip() = 0; 
	
	/**
	 * @brief Cancels the launch
	 * 
	 */
	virtual void Cancel() = 0;
};

#endif