/**
 * @file
 * @author Rina Rene du Toit
 *
 * @brief
 *
 * Design Pattern: Template in State
 * Participant: Concrete class
 */

#ifndef MERLINENGINE_H
#define MERLINENGINE_H

using namespace std;

#include "Engine.h"
#include <iostream>

class MerlinEngine : public Engine {
public:
	/**
	 * Constructor for MerlinEngine Class
	 */
	MerlinEngine();
	/**
	 * Destructor for MerlinEngine Class
	 */
	~MerlinEngine();
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