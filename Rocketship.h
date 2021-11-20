#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

using namespace std;
#include <iostream>
#include "Station.h"

class Rocketship
{
public:
	Rocketship(string n, char);
	~Rocketship();
	virtual void Launch() = 0;
	virtual Rocketship *clone() = 0;
	string getName();
	void countdown();
	char getType();
	void attachToStation(Station *);
	Station *getStation();

private:
	string name;
	char rocketshipType; // s d c
	Station *current_Station;
};

#endif