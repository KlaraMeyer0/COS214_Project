/**
 * @file FalconHeavyFactory.h
 * @author your name (you@domain.com)
 * @brief 
 * Design Pattern: Factory Method
 * Participant: Factory
 * 
 */
#ifndef FALCONHEAVYFACTORY_H
#define FALCONHEAVYFACTORY_H

using namespace std;

#include "RocketFactory.h"

class FalconHeavyFactory : public RocketFactory {
public:
	/**
	 * @brief Construct a new Falcon Heavy Factory object
	 * 
	 */
	FalconHeavyFactory();
	/**
	 * @brief Destroy the Falcon Heavy Factory object
	 * 
	 */
	virtual ~FalconHeavyFactory();
protected:
	/**
	 * @brief Creates a FalconHeavy rocket and returns a pointer to it
	 * 
	 * @return FalconRocket* 
	 */
    FalconRocket* createRocket();
};

#endif