/**
 * @file Spacecraft.h
 * @class Spacecraft
 * @author Xander Coetzer
 * @brief Design Pattern: Factory Method, Participant: Product
 */
#ifndef SPACECRAFT_H
#define SPACECRAFT_H

using namespace std;

class Spacecraft
{
public:
	/**
	 * @brief Constructs a new Spacecraft object
	 * 
	 * @param capacity the amount of cargo that a spaceship can take into space
	 */
	Spacecraft(int capacity);
	/**
	 * @brief Destroys the Spacecraft object
	 * 
	 */
	virtual ~Spacecraft();
	/**
	 * @brief Get the Capacity of the spacecraft
	 * 
	 * @return int 
	 */
	int getCapacity();
	/**
	 * @brief Creates a clone of the current spacecraft in the rocketship
	 * 
	 * @return Spacecraft* 
	 */
	virtual Spacecraft *clone() = 0;

private:
	/**
	 * @brief Stores the specified capacity of the spacecraft
	 * 
	 */
	int cargoCapacity;
};

#endif