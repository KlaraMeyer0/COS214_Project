/**
 * @file Falcon9.h
 * @author Rina Rene du Toit
 * @class Falcon9
 * @brief
 * Design Pattern: State
 * Participant: Context
 */

#ifndef FALCON9_H
#define FALCON9_H

using namespace std;

#include "_9Engine.h"
#include "FalconRocket.h"

class Falcon9 : public FalconRocket {
public:
	/**
	 * Constructor for Falcon9 Class
	 */
	Falcon9();
	/**
	 * Destructor for Falcon9 Class
	 */
	virtual ~Falcon9();
	/**
	 * Part of the Prototype DP that is used my the Memento DP to copy the Falon9
	 * @return Copy of the current object
	 */
	FalconRocket* clone();
};

#endif