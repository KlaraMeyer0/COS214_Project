/**
 * @file StageEngine.h
 * @author Rina Rene du Toit
 * @class StageEngine
 * @brief Design Pattern: State Participant: State
 */

#ifndef STAGEENGINE_H
#define STAGEENGINE_H

using namespace std;

#include "FalconRocket.h"
#include <iostream>

class FalconRocket;

class StageEngine {
public:
	/**
	 * Constructor for StageEngine Class
	 */
	StageEngine();
	/**
	 * Destructor for StageEngine Class
	 */
	virtual ~StageEngine();
	/**
	 * Pure virtaul function - Turn on the engine
	 */
	virtual void TurnOn(FalconRocket*) = 0;
	/**
	 * Pure virtaul function - Turn off the engine
	 */
	virtual void TurnOff(FalconRocket*) = 0;
	/**
	 * Pure virtaul function - Returns the number of engines
	 * @return The number of engines in the rocket
	 */
	virtual int EngineCount() = 0;
	/**
	 * Pure virtaul function - Returns if engines are on
	 * @return The state of the engines
	 */
	virtual bool getState() = 0;
	/**
	 * @brief Does a static fire test
	 * 
	 * @return true 
	 * @return false 
	 */
	bool testFire();
};

#endif