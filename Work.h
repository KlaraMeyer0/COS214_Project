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