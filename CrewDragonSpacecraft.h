/**
 * @file CrewDragonSpacecraft.h
 * @author your name (you@domain.com)
 * @brief 
 * Design Pattern: Factory Method
 * Participant: Concrete Product
 * 
 */
#ifndef CREWDRAGONSPACECRAFT_H
#define CREWDRAGONSPACECRAFT_H

using namespace std;

#include "Spacecraft.h"

class CrewDragonSpacecraft : public Spacecraft {
public:
	/**
	 * @brief Constructs a new Crew Dragon Spacecraft
	 * 
	 * @param capacity The size of the storage space of the CrewDragon spacecraft
	 */
	CrewDragonSpacecraft(int capacity);
	/**
	 * @brief Destroys the Crew Dragon Spacecraft
	 * 
	 */
	virtual ~CrewDragonSpacecraft();
	/**
	 * @brief Creates a deep copy of the CrewDragon spacecraft and returns a pointer to it
	 * 
	 * @return Spacecraft* 
	 */
	Spacecraft* clone();
};

#endif