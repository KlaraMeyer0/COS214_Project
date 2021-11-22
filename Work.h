/**
 * @file Work.h
 * @author {James Butler, Xander Coetzer}
 * @brief 
 * 
 * Design Pattern: Command
 * Participant: Command
 */
#ifndef WORK_H
#define WORK_H

using namespace std;
#include "LaunchInterface.h"

class Work {
public:
	/**
	 * @brief Construct a new Work object
	 * 
	 * @param launch_interface The launch interface to affect with commands
	 */
	Work(LaunchInterface* launch_interface){
		this->launch_interface = launch_interface;
	}

	/**
	 * @brief Destroy the Work object
	 * 
	 */
	virtual ~Work(){
		launch_interface = nullptr;
	}
	/**
	 * @brief Executes the concrete command
	 * 
	 */
	virtual void execute() = 0;
	/**
	 * @brief Undos the concrete command
	 * 
	 */
	virtual void undo() = 0;
protected:
	/**
	 * @brief holds the launch interface to which all the rocketships will be added
	 *
	 */
	LaunchInterface *launch_interface;
};

#endif