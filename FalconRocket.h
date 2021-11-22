/**
 * @file FalconRocket.h
 * @author Rina Rene du Toit
 * @class FalconRocket
 * @brief Design Pattern: State Participant: Context
 */

#ifndef FALCONROCKET_H
#define FALCONROCKET_H

using namespace std;

#include "StageEngine.h"
class StageEngine;

class FalconRocket {
protected:
	/**
	 * Variable storing the state of the rocket
	 */
	StageEngine* stage;
public:
	/**
	 * Constructor for FalconRocket Class
	 */
	FalconRocket();
	/**
	 * Destructor for FalconRocket Class
	 */
	virtual ~FalconRocket();
	/**
	 * Detach the state
	 */
	void detach();
	/**
	 * Attach a new state
	 */
	void attach(StageEngine*);
	/**
	 * Turn on the engine
	 */
	void turnOn();
	/**
	 * Turn off the engine
	 */
	void turnOff();
	/**
	 * Pure virtaul function - Part of the Prototype DP that is used my the Memento DP to copy the Falon9
	 * @return Copy of the current object
	 */
	virtual FalconRocket* clone() = 0;
	/**
	 * Returns the attached engine
	 * @return Current StageEngine storing the stage of the rocket
	 */
	StageEngine* getEngine();
	/**
	 * Returns if engines are currently on
	 * @return The state of the engines
	 */
	bool getState();
};

#endif