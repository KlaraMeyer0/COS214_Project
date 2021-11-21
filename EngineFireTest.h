/**
 * @file EngineFireTest.h
 * @author James Butler
 * @brief 
 * 
 * Design Pattern: Decorator
 * Participant: Concrete Decorator
 */
#ifndef ENGINEFIRETEST_H
#define ENGINEFIRETEST_H

#include "LaunchTest.h"

using namespace std;

class EngineFireTest : public LaunchTest {
public:
	/**
	 * @brief Construct a new Engine Fire Test object
	 * 
	 * @param la The component to decorate
	 */
	EngineFireTest(Launch* la);

	/**
	 * @brief Destroy the Engine Fire Test object
	 * 
	 */
	virtual ~EngineFireTest();

	/**
	 * @brief Tests if the engines all fire
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