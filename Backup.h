/**
 * @file Backup.h
 * @class Backup
 * @author James Butler
 * @brief 
 * 
 * Design Pattern: Memento, Command
 * Participant: Client, Concrete Command
 */
#ifndef BACKUP_H
#define BACKUP_H

using namespace std;

#include "Work.h"

class Backup : public Work{
public:
    /**
     * @brief Construct a new Backup object
     * 
     * @param l Pointer to the launch interface that will make the backup
     */
	Backup(LaunchInterface* l);

    /**
     * @brief Destroy the Backup object
     * 
     */
    virtual ~Backup();

    /**
     * @brief Creates a backup of the current launch interface's setup of rockets to launch
     * 
     */
    void execute();

    /**
     * @brief Restores a stored setup to the launch interface
     * 
     */
    void undo();
};

#endif