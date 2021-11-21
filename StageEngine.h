/**
 * @file
 * @author Rina Rene du Toit
 *
 * @brief
 *
 * Design Pattern: State
 * Participant: State
 */

#ifndef STAGEENGINE_H
#define STAGEENGINE_H

using namespace std;

#include "FalconRocket.h"

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
	 * @return Current StageEngine storing the stage of the rocket
	 */
	virtual int EngineCount() = 0;
	/**
	 * Pure virtaul function - Returns if engines are on
	 * @return The state of the engines
	 */
	virtual bool getState() = 0;
};

#endif