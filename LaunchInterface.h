/**
 * @file LaunchInterface.h
 * @author James Butler
 * @brief 
 * 
 * Design Pattern: Memento
 * Participant: Originator
 */
#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

#include "Rocketship.h"
#include "LaunchCaretaker.h"
#include "LaunchReal.h"
#include "EnginePresentTest.h"
#include "EngineFireTest.h"
#include "StopTest.h"
#include "CargoTest.h"
#include "LaunchFile.h"
#include <sstream>

using namespace std;

class LaunchInterface {
public:
	/**
	 * @brief Construct a new Launch Interface object
	 * 
	 */
	LaunchInterface();

	/**
	 * @brief Destroy the Launch Interface object
	 * 
	 */
	virtual ~LaunchInterface();

	/**
	 * @brief Create backup Launchfile for current selection of rockets
	 * 
	 * @return LaunchFile* 
	 */
	LaunchFile* retrieveLaunchFile();

	/**
	 * @brief Sets the given Launchfile as the current rocket setup
	 * 
	 */
	void setLaunchFile(LaunchFile*);

	/**
	 * @brief Starts a launch by prompting the user about which rockets to launch,
	 * prompting about the type of launch, and then run the tests for each rocket and launch them
	 * 
	 */
	void TestLaunch();

	/**
	 * @brief Adds a rocket to the current setup
	 * 
	 */
	void addRocketship(Rocketship*);

	/**
	 * @brief Store the current file into Caretaker
	 * 
	 */
	void storeFile();

	/**
	 * @brief Check if current setup is backed up
	 * 
	 */
	void restoreFile();

	/**
	 * @brief Outputs the descriptions of of all stored setups
	 * 
	 */
	void outputDesc();

	/**
	 * @brief Outputs the current rocketship setup's descriptions
	 * 
	 */
	void getDesc();
private:
	/**
	 * @brief An array of rocketships, the current setup
	 * 
	 */
    Rocketship** rocketships;

	/**
	 * @brief The caretaker to store and retreives setups of rocketships
	 * 
	 */
	LaunchCaretaker* launchCaretaker;

	/**
	 * @brief The number of rockets in the current setup
	 * 
	 */
	int rocketCount;
};

#endif