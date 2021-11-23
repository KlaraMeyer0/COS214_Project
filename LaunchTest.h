/**
 * @file LaunchTest.h
 * @author James Butler
 * @class LaunchTest
 * 
 * @brief 
 * 
 * Design Pattern: Decorator
 * Participant: Decorator
 */
#ifndef LAUNCHTEST_H
#define LAUNCHTEST_H

#include "Launch.h"
#include <iostream>
#include <sstream>

using namespace std;

class LaunchTest : public Launch {
public:
	/**
	 * @brief Construct a new Launch Test object
	 * 
	 * @param la Sets the Component to decorate
	 */
	LaunchTest(Launch* la){
		l = la;
	};

	/**
	 * @brief Destroy the Launch Test object
	 * 
	 */
	virtual ~LaunchTest(){
		delete l;
	};

	/**
	 * @brief Implements the concrete decorators' functions
	 * 
	 */
    virtual void output() = 0;

	/**
	 * @brief Calls the output() function and then the component's startLaunch() function
	 * 
	 */
	virtual void startLaunch() = 0;

	/**
	 * @brief Get the Ship object
	 * 
	 * @return Rocketship* 
	 */
	virtual Rocketship* getShip(){
		return l->getShip();
	};

	/**
	 * @brief Cancels the launch
	 * 
	 */
	virtual void Cancel(){
		l->Cancel();
	};
protected:
	/**
	 * @brief The decorated component
	 * 
	 */
	Launch* l;
};

#endif