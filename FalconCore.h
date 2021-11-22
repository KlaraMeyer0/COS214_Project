/**
 * @file FalconCore.h
 * @author Rina Rene du Toit
 * @class FalconCore
 * @brief Design Pattern: Template in State Participant: Concrete class
 */

#ifndef FALCONCORE_H
#define FALCONCORE_H

using namespace std;

#include "Engine.h"
#include "MerlinEngine.h"
#include <iostream>

class FalconCore : public Engine {
private:
	/**
	 * Array of merlin engines
	 */
	MerlinEngine** merlins; 
	/**
	 * Used for testing
	 */
	const int EngineCount = 9; //Don't remove
public:
	/**
	 * Constructor that initialises its the Merlin engines
	 */
	FalconCore();
	/**
	 * Destructor for the FalconCore class
	 */
	~FalconCore();
	/**
	 * Turn on the Falcon Core engine as well as its Merlin egines
	 */
	void TurnOn();
	/**
	 * Turn off the Falcon Core engine as well as its Merlin egines
	 */
	void TurnOff();
	/**
	 * Returns number of engines in core
	 * @return number of merlin engines attached
	 */
	int getCount();
};

#endif