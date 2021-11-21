/**
 * @file Cargo.h
 * @author Xander Coetzer
 * @brief 
 * 
 * Design Pattern: Factory
 * Participant: Product
 */
#ifndef CARGO_H
#define CARGO_H

#include <string>

using namespace std;

class Cargo {
public:
    /**
     * @brief Construct a new Cargo object
     * 
     * @param n The name of the cargo
     * @param h Whether the object is human or not
     */
	Cargo(string n, bool h);

    /**
     * @brief Destroy the Cargo object
     * 
     */
	virtual ~Cargo();

    /**
     * @brief Get the name of the cargo
     * 
     * @return string 
     */
    string getName();

    /**
     * @brief Returns if the cargo is human or not
     * 
     * @return true 
     * @return false 
     */
    bool isHuman();

    /**
     * @brief Creates a deep copy of this object
     * 
     * @return Cargo* 
     */
    virtual Cargo* clone() = 0;
private:
    /**
     * @brief The name of the cargo
     * 
     */
    string name;

    /**
     * @brief Whether it is human or not
     * 
     */
    bool human;
};

#endif