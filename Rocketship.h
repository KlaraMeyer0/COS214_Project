#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

using namespace std;
#include <iostream>
#include <unistd.h>
#include "Station.h"
#include "FalconRocket.h"

class Rocketship
{
public:
	Rocketship(string n, char);//initialises 
	~Rocketship();
	virtual void Launch() = 0;//launches the rocket into space and attaches it to the space station
	virtual Rocketship *clone() = 0;
	string getName();//return name of the rocketship
	void countdown();//countdown before launch
	char getType();//returns the type of the rocket(DragonRocketship, CrewDragonRocketship or StarlinkCollection)
	void attachToStation(Station *); //attaches the specefic rocketship to a base or space station
	Station *getStation(); //returns the station that the rocketship is currently attached to.
	virtual int getRockets() = 0;//gives a count of the engines on this spaceship setup
	virtual bool testFire() = 0;//returns if the engines are on or not
	virtual bool testLoading() = 0;//returns if cargo has been loaded
private:
	string name;
	char rocketshipType; // s d c
	Station *current_Station;
};

#endif