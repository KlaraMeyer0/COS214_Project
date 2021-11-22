/**
 * @file CrewDragonFactory.h
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Factory Method
 * Participant: Factory
 * 
 */
#ifndef CREWDRAGONFACTORY_H
#define CREWDRAGONFACTORY_H

using namespace std;

#include "SpacecraftFactory.h"

class CrewDragonFactory : public SpacecraftFactory {
public:
	/**
	 * @brief Construct a new Crew Dragon Factory object
	 * 
	 */
	CrewDragonFactory();
	/**
	 * @brief Destroy the Crew Dragon Factory object
	 * 
	 */
	virtual ~CrewDragonFactory();
protected:
	/**
	 * @brief Creates a crewDragon spacecraft and returns a pointer to it
	 * 
	 * @return Spacecraft* 
	 */
    Spacecraft* createRocket();
};

#endif