/**
 * @file Equipment.h
 * @class Equipment
 * @author Xander Coetzer
 * @brief
 * Design Pattern: Factory Method
 * Participant: Concrete Product
 *
 */
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

using namespace std;

#include "Cargo.h"

class Equipment : public Cargo
{
public:
	/**
	 * @brief Construct a new Equipment object
	 *
	 * @param s String which identifies the equipment
	 */
	Equipment(string s);
	/**
	 * @brief Destroy the Equipment object
	 *
	 */
	virtual ~Equipment();
	/**
	 * @brief Creates a deep copy of the euipment object
	 *
	 * @return Cargo*
	 */
	Cargo *clone();
};

#endif