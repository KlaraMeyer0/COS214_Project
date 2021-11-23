/**
 * @file Engine.h
 * @author Rina Rene du Toit
 * @class Engine
 * @brief Design Pattern: Template in State Participant: Abstract class
 */

#ifndef ENGINE_H
#define ENGINE_H

using namespace std;

class Engine {
public:
	/**
	 * Constructor that initailises the On attribute to true
	 */
	Engine();
	/**
	 * Destructor of the engine
	 */
	virtual ~Engine();
	/**
     * Pure virtual function for turning on the engine
     */
	virtual void TurnOn() = 0;
	/**
     * Pure virtual function for turning off the engine
     */
	virtual void TurnOff() = 0;
	/**
     * Function for getting the state of the engine
	 * @return The On attribute, saves weither the engine is on or not
     */
	virtual bool getState();
protected:
	/**
	 * Variable storing weither the engine is on or not
	 */
	bool On;
};

#endif