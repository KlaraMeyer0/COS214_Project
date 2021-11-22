/**
 * @file TestLaunch.h
 * @author James Butler
 * 
 * @brief
 * 
 * Design Pattern: Command
 * Participant: Concrete Command
 */
#ifndef TESTLAUNCH_H
#define TESTLAUNCH_H

using namespace std;

#include "Work.h"
#include "Rocketship.h"

class TestLaunch : public Work{
public:
    /**
     * @brief Construct a new Test Launch object
     * 
     * @param l Pointer to the launch interface to launch with
     */
	TestLaunch(LaunchInterface* l);

    /**
     * @brief Destroy the Test Launch object
     * 
     */
	virtual ~TestLaunch();

    /**
     * @brief Executes the contained interface's testLaunch() function
     * 
     */
    void execute();

    /**
     * @brief Sends back the rockets from the spacestation
     * 
     */
    void undo();
};

#endif