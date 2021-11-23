/**
 * @file EquipmentFactory.h
 * @class EquipmentFactory
 * @author Xander Coetzer
 * @brief 
 * 
 * Design Pattern: Factory
 * Participant: Concrete Factory
 */
#ifndef EQUIPMENTFACTORY_H
#define EQUIPMENTFACTORY_H

using namespace std;

#include "CargoFactory.h"

class EquipmentFactory : public CargoFactory {
public:
	/**
	 * @brief Construct a new Equipment Factory object
	 * 
	 */
	EquipmentFactory();

	/**
	 * @brief Destroy the Equipment Factory object
	 * 
	 */
	virtual ~EquipmentFactory();
protected:
	/**
	 * @brief Creates a new Equipment object with name n
	 * 
	 * @param n The name
	 * @return Cargo* 
	 */
    Cargo* getCargo(string n);
};

#endif