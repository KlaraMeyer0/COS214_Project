#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

using namespace std;
#include <iostream>

class Rocketship
{
public:
	Rocketship(string n);
	~Rocketship();
	virtual void Launch() = 0;
	virtual Rocketship *clone() = 0;
	string getName();
	void countdown();

private:
	string name;
};

#endif