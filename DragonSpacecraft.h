/**
 * @file CreateDragon.h
 * @author Xander Coetzer
 * @brief 
 * Design Pattern:
 * Participant
 * 
 */
#ifndef DRAGONSPACECRAFT_H
#define DRAGONSPACECRAFT_H

using namespace std;

#include "Spacecraft.h"

class DragonSpacecraft : public Spacecraft {
public:
	DragonSpacecraft(int capacity);
	virtual ~DragonSpacecraft();
	Spacecraft* clone();
};

#endif