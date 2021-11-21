/**
 * @file
 * @author Rina Rene du Toit
 *
 * @brief
 *
 * Design Pattern: State
 * Participant: Concrete State
 */

#ifndef HeavyENGINE_H
#define HeavyENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "Stage2Engine.h"
#include "FalconCore.h"
#include "FalconRocket.h"

class HeavyEngine : public Stage1Engine {
private:
	/**
	 * Array of falcon cores, the engine used in this state
	 */
	FalconCore** cores;
public:
	/**
	 * Constructor for HeavyEngine Class
	 */
	HeavyEngine();
	/**
	 * Destructor for HeavyEngine Class
	 */
	virtual ~HeavyEngine();
	/**
	 * Turn on the rocket's engine
	 */
	void TurnOn(FalconRocket*);
	/**
	 * Turn off the rocket's engine
	 */
	void TurnOff(FalconRocket*);
	/**
	 * Returns the number of engines
	 * @return Current StageEngine storing the stage of the rocket
	 */
	virtual int EngineCount();
	/**
	 * Get state of engines
	 * @return The state of the engines
	 */
	virtual bool getState(); 
};

#endif