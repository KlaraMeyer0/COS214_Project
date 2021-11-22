/**
 * @file RocketFactory.h
 * @author your name (you@domain.com)
 * @brief 
 * Design Pattern: Factory Method
 * Participant: Abstract Factory
 * 
 */
#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H

#include "FalconRocket.h"

class RocketFactory {
public:
    /**
     * @brief Construct a new Rocket Factory object
     * 
     */
	RocketFactory();
    /**
     * @brief Destroy the Rocket Factory object
     * 
     */
	virtual ~RocketFactory();
    /**
     * @brief calls the createRocket and returns the created rocket
     * 
     * @return FalconRocket* 
     */
    FalconRocket* startFactory();
protected:
    /**
     * @brief Create a Rocket object. This can be either a Falcon9 rocket or a FalconHeavy rocket
     * 
     * @return FalconRocket* 
     */
    virtual FalconRocket* createRocket() = 0;
};

#endif