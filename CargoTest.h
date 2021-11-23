/**
 * @file CargoTest.h
 * @class CargoTest
 * @author James Butler
 * @brief Inherits from LaunchTest, Design pattern: Decorator, Participant: Concrete Decorator
 */
#ifndef CARGOTEST_H
#define CARGOTEST_H

using namespace std;

#include "LaunchTest.h"

class CargoTest : public LaunchTest{
public:
	/**
	 * @brief Construct a new Cargo Test object
	 * 
	 * @param la The component to decorate
	 */
	CargoTest(Launch* la);
	
	/**
	 * @brief Destroy the Cargo Test object
	 * 
	 */
	virtual ~CargoTest();

	/**
	 * @brief Tests if cargo is attached to the rocketship being launched
	 * 
	 */
    void output();

	/**
	 * @brief Calls the output() function and the component's startLaunch() function
	 * 
	 */
	virtual void startLaunch();
	
};

#endif