/**
 * @file EnginePresentTest.h
 * @class EnginePresentTest
 * @author James Butler
 * @brief 
 * 
 * Design Pattern: Decorator
 * Participant: Concrete Decorator
 */
#ifndef ENGINEPRESENTTEST_H
#define ENGINEPRESENTTEST_H

#include "LaunchTest.h"

using namespace std;

class EnginePresentTest : public LaunchTest{
public:
	/**
	 * @brief Construct a new Engine Present Test object
	 * 
	 * @param la The Component to decorate
	 */
	EnginePresentTest(Launch* la);

	/**
	 * @brief Destroy the Engine Present Test object
	 * 
	 */
	virtual ~EnginePresentTest();

	/**
	 * @brief Tests if the correct number of engines are attatched
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