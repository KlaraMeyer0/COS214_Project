/**
 * @file LaunchCaretaker.h
 * @author James Butler
 * @brief 
 * 
 * Design Pattern: Memento
 * Participant: Caretaker
 */
#ifndef LAUNCHCARETAKER_H
#define LAUNCHCARETAKER_H

using namespace std;

#include "LaunchFile.h"

class LaunchCaretaker {
public:
	/**
	 * @brief Construct a new Launch Caretaker object
	 * 
	 */
	LaunchCaretaker();

	/**
	 * @brief Destroy the Launch Caretaker object
	 * 
	 */
	virtual ~LaunchCaretaker();

	/**
	 * @brief Get the File object at index i
	 * 
	 * @param i the index to select it 
	 * @return LaunchFile* 
	 */
	LaunchFile* getFile(int i);

	/**
	 * @brief Set the File object
	 * 
	 * @param newfile The file to store
	 */
	void setFile(LaunchFile* newfile);

	/**
	 * @brief Get the Description of the file at index i
	 * 
	 * @param i The index
	 * @return string 
	 */
	string getDesc(int i);

	/**
	 * @brief Remove the file at index i
	 * 
	 * @param i The index
	 */
	void removeFile(int i);

	/**
	 * @brief Returns true if the provided LaunchFile is stored, else false
	 * 
	 * @param f The launchFile to search for
	 * @return bool
	 */
	bool contains(LaunchFile* f);

	/**
	 * @brief Returns true if the Rocketship array passed in is stored
	 * 
	 * @param r The Rocketship array to check
	 * @return bool
	 */
	bool contains(Rocketship** r);

	/**
	 * @brief Get the number of stored files
	 * 
	 * @return int 
	 */
	int getSize();
private:
	/**
	 * @brief An array of LaunchFiles being stored
	 * 
	 */
    LaunchFile** file;

	/**
	 * @brief A description of the stored rockets in this object
	 * 
	 */
	string* desc;

	/**
	 * @brief The number of stored LaunchFiles
	 * 
	 */
	int FileSize;
};

#endif