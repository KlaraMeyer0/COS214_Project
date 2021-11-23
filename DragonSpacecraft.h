/**
 * @file DragonSpacecraft.h
 * @class DragonSpacecraft
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Factory Method
 * Participant: Concrete Product
 * 
 */
#ifndef DRAGONSPACECRAFT_H
#define DRAGONSPACECRAFT_H

using namespace std;

#include "Spacecraft.h"

class DragonSpacecraft : public Spacecraft {
public:
	/**
	 * @brief Constructs a new Dragon Spacecraft
	 * 
	 * @param capacity The size of the storage space of the Dragon spacecraft
	 */
	DragonSpacecraft(int capacity);
	/**
	 * @brief Destroys the Dragon Spacecraft
	 * 
	 */
	virtual ~DragonSpacecraft();
	/**
	 * @brief Creates a deep copy of the Dragon spacecraft and returns a pointer to it
	 * 
	 * @return Spacecraft* 
	 */
	Spacecraft* clone();
};

#endif