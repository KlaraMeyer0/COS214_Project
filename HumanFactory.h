/**
 * @file HumanFactory.h
 * @author Xander Coetzer
 * @class HumanFactory
 * @brief 
 * 
 * Design Pattern: Factory
 * Participant: Concrete Factory
 */
#ifndef HUMANFACTORY_H
#define HUMANFACTORY_H

#include <string>
#include <iostream>
using namespace std;

#include "CargoFactory.h"

class HumanFactory : public CargoFactory
{
public:
	/**
	 * @brief Construct a new Human Factory object
	 * 
	 */
	HumanFactory();
	/**
	 * @brief Destroy the Human Factory object
	 * 
	 */
	virtual ~HumanFactory();
protected:
	/**
	 * @brief Creates a new Human object with name n
	 * 
	 * @param n The name
	 * @return Cargo* 
	 */
	Cargo *getCargo(string n);
};

#endif