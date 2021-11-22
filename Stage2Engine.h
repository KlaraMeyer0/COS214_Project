/**
 * @file Stage2Engine.h
 * @author Rina Rene du Toit
 * @class Stage2Engine
 * @brief Design Pattern: State Participant: Concrete State
 */

#ifndef STAGE2ENGINE_H
#define STAGE2ENGINE_H

using namespace std;

#include "VacuumEngine.h"
#include "FalconRocket.h"
#include "StageEngine.h"

class Stage2Engine : public StageEngine {
private:
	/**
	 * Variable holding a pointer to the engine
	 */
	VacuumEngine* engine;
public:
	/**
	 * Constructor for Stage2Engine Class
	 */
	Stage2Engine();
	/**
	 * Destructor for Stage2Engine Class
	 */
	virtual ~Stage2Engine();
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
	int EngineCount();
	/**
	 * Returns the state that the engine is in
	 * @return The state of the engines
	 */
	bool getState(){return true;};
};

#endif