/**
 * @file Stage1Engine.h
 * @author Rina Rene du Toit
 * @class Stage1Engine
 * @brief
 * Design Pattern: State
 * Participant: State
 */

#ifndef STAGE1ENGINE_H
#define STAGE1ENGINE_H

using namespace std;

#include "FalconRocket.h"
#include "StageEngine.h"

class Stage1Engine : public StageEngine {
public:
	/**
	 * Constructor for Stage1Engine Class
	 */
	Stage1Engine();
	/**
	 * Destructor for Stage1Engine Class
	 */
	virtual ~Stage1Engine();
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
	 * Pure virtaul function - Returns the state that the engine is in
	 * @return The state of the engines
	 */
	virtual bool getState() = 0;
};

#endif