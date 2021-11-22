/**
 * @file FalconHeavy.h
 * @author Rina Rene du Toit
 * @class FalconHeavy
 * @brief
 * Design Pattern: State
 * Participant: Context
 */

#ifndef FALCONHEAVY_H
#define FALCONHEAVY_H

using namespace std;

#include "HeavyEngine.h"
#include "FalconRocket.h"

class FalconHeavy : public FalconRocket {
public:
	/**
	 * Constructor for FalconHeavy Class
	 */
	FalconHeavy();
	/**
	 * Destructor for FalconHeavy Class
	 */
	virtual ~FalconHeavy();
	/**
	 * Part of the Prototype DP that is used my the Memento DP to copy the FalonHeavy
	 * @return Copy of the current object
	 */
	FalconRocket* clone();
};

#endif