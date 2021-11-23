/**
 * @file VacuumEngine.h
 * @author Rina Rene du Toit
 * @class VacuumEngine
 * @brief Inherts from Engine, Design Pattern: Template in State, Participant: Concrete class
 */

#ifndef VACUUMENGINE_H
#define VACUUMENGINE_H

using namespace std;

#include "Engine.h"
#include <iostream>

class VacuumEngine : public Engine {
public:
	/**
	 * Constructor for VacuumEngine Class
	 */
	VacuumEngine();
	/**
	 * Destructor for VacuumEngine Class
	 */
	~VacuumEngine();
	/**
	 * Turn on the engine
	 */
	void TurnOn();
	/**
	 * Turn off the engine
	 */
	void TurnOff();
};

#endif