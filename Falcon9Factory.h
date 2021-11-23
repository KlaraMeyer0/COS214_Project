/**
 * @file Falcon9Factory.h
 * @class Falcon9Factory
 * @author Xander Coetzer
 * @brief Inherits from RocketFactory, Design Pattern: Factory Method, Participant: Factory
 */
#ifndef FALCON9FACTORY_H
#define FALCON9FACTORY_H

using namespace std;

#include "RocketFactory.h"

class Falcon9Factory : public RocketFactory {
public:
	/**
	 * @brief Construct a new Falcon 9 Factory object
	 * 
	 */
	Falcon9Factory();
	/**
	 * @brief Destroy the Falcon 9 Factory object
	 * 
	 */
	virtual ~Falcon9Factory();
protected:
	/**
	 * @brief Creates a Falcon9 rocket and returns a pointer to it
	 * 
	 * @return FalconRocket* 
	 */
    FalconRocket* createRocket();
};

#endif