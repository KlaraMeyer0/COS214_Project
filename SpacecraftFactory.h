/**
 * @file SpacecraftFactory.h
 * @class SpacecraftFactory
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Factory Method
 * Participant: Abstract Factory
 * 
 */
#ifndef SPACECRAFTFACTORY_H
#define SPACECRAFTFACTORY_H

#include "Spacecraft.h"

class SpacecraftFactory {
public:
    /**
     * @brief Construct a new Spacecraft Factory object
     * 
     */
	SpacecraftFactory();
    /**
     * @brief Destroy the Spacecraft Factory object
     * 
     */
	virtual ~SpacecraftFactory();
    /**
     * @brief calls the createRocket and returns the created spacecraft
     * 
     * @return Spacecraft* 
     */
    Spacecraft* startFactory();
protected:
    /**
     * @brief Creates a spacecraft object. This can be either a DragonSpacecraft or a CrewDragonSpacecraft
     * 
     * @return Spacecraft* 
     */
    virtual Spacecraft* createRocket() = 0;
};

#endif