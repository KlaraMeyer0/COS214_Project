/**
 * @file CargoFactory.h
 * @class CargoFactory
 * @author Xander Coetzer
 * @brief 
 * Design Pattern: Factory Method
 * Participant: Abstract Factory 
 * 
 */
#ifndef CARGOFACTORY_H
#define CARGOFACTORY_H

#include "Cargo.h"

class CargoFactory
{
public:
    /**
     * @brief Construct a new Cargo Factory object
     * 
     */
    CargoFactory();
    /**
     * @brief Destroy the Cargo Factory object
     * 
     */
    virtual ~CargoFactory();
    /**
     * @brief Calls the protected getCargo function and returns the result. Resembles the anOperation().
     * 
     * @param n String that describes the cargo
     * @return Cargo* which is either Human or Equipment.
     */
    Cargo *startFactory(string n);
protected:
    /**
     * @brief Creates the Cargo object and returns the result. Resembles the factoryMethod().
     * 
     * @param n String that describes the cargo
     * @return Cargo* 
     */
    virtual Cargo *getCargo(string n) = 0;
};

#endif