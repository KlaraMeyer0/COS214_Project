/**
 * @file Human.h
 * @author Xander Coetzer
 * @class Human
 * @brief 
 * 
 * Design Pattern: Factory
 * Participant: Concrete Product
 */
#ifndef HUMAN_H
#define HUMAN_H

using namespace std;

#include "Cargo.h"

class Human : public Cargo {
public:
	/**
	 * @brief Construct a new Human object
	 * 
	 * @param n The name of the human
	 */
	Human(string n);

	/**
	 * @brief Destroy the Human object
	 * 
	 */
	virtual ~Human();

	/**
	 * @brief Creates a deep copy of this object
	 * 
	 * @return Cargo* 
	 */
    Cargo* clone();
};

#endif