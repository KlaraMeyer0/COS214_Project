/**
 * @file LaunchFile.h
 * @author James Butler
 * @class LaunchFile
 * @brief Design Pattern: Memento, Participant: Memento
 */
#ifndef LAUNCHFILE_H
#define LAUNCHFILE_H

#include "Rocketship.h"

using namespace std;

class LaunchFile {
public:
    /**
     * @brief Construct a new Launch File object
     * 
     */
	LaunchFile();

    /**
     * @brief Destroy the Launch File object
     * 
     */
	virtual ~LaunchFile();

    /**
     * @brief Get the stored setup of rocketships
     * 
     * @return Rocketship** 
     */
    Rocketship** getLaunch();

    /**
     * @brief Set the setup of rocketships to store
     * 
     * @param rocketships The rocketships to store
     * @param c The number of rockets to store
     */
    void setLaunch(Rocketship** rocketships,int c);

    /**
     * @brief Get the Count object
     * 
     * @return int 
     */
    int getCount();
private:
    /**
     * @brief The stored array of rocketships
     * 
     */
    Rocketship** rocketships;

    /**
     * @brief the number of stored rocketships
     * 
     */
    int count;
};

#endif
