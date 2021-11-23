/**
 * @file StopTest.h
 * @class StopTest
 * @author James Butler
 * @brief 
 * 
 * Design Pattern: Decorator
 * Participant: Concrete Decorator
 */
#ifndef STOPTEST_H
#define STOPTEST_H

using namespace std;

#include "LaunchTest.h"

class StopTest : public LaunchTest {
public:
	/**
	 * @brief Construct a new Stop Test object
	 * 
	 * @param l The Component to decorate
	 */
	StopTest(Launch* l);

	/**
	 * @brief Destroy the Stop Test object
	 * 
	 */
	virtual ~StopTest();

	/**
	 * @brief Stops the occuring testlaunch and allows for continuation or abortion
	 * 
	 */
    void output();

	/**
	 * @brief Calls the output() function and then the decorated component's startLaunch() function
	 * 
	 */
	virtual void startLaunch();
private:
	/**
	 * @brief Stores whether the launch should be continued or aborted
	 * 
	 */
	bool flag;
};

#endif