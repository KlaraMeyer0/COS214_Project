/**
 * @file DragonFactory.h
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Factory Method
 * Participant: Factory
 * 
 */
#ifndef DRAGONFACTORY_H
#define DRAGONFACTORY_H

using namespace std;

#include "SpacecraftFactory.h"

class DragonFactory : public SpacecraftFactory {
public:
	/**
	 * @brief Construct a new Dragon Factory object
	 * 
	 */
	DragonFactory();
	/**
	 * @brief Destroy the Dragon Factory object
	 * 
	 */
	virtual ~DragonFactory();
protected:
	/**
	 * @brief Creates a Dragon spacecraft and returns a pointer to it
	 * 
	 * @return Spacecraft* 
	 */
    Spacecraft* createRocket();
};

#endif