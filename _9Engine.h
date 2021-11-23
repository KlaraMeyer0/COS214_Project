/**
 * @file _9Engine.h
 * @author Rina Rene du Toit
 * @class _9Engine
 * @brief Inherts from Engine Stage1Engine, Design Pattern: State, Participant: Concrete State
 */

#ifndef _9ENGINE_H
#define _9ENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "Stage2Engine.h"
#include "FalconCore.h"
#include "FalconRocket.h"

class _9Engine : public Stage1Engine {
private:
	/**
	 * Pointer to FalconCore engine
	 */
	FalconCore* core;
public:
	/**
	 * Constructor for _9Engine Class
	 */
	_9Engine();
	/**
	 * Destructor for _9Engine Class
	 */
	virtual ~_9Engine();
	/**
	 * Turn on the engine
	 */
	void TurnOn(FalconRocket*);
	/**
	 * Turn off the engine
	 */
	void TurnOff(FalconRocket*);
	/**
	 * Returns the number of engines//Blank//Required for testing
	 * @return Current StageEngine storing the stage of the rocket
	 */
	virtual int EngineCount();
	/**
	 * Returns the state that the engine is in
	 * @return The state of the engines
	 */
	virtual bool getState();
};

#endif