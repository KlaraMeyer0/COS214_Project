#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

using namespace std;
#include <iostream>

class Rocketship
{
public:
	Rocketship(string n,char);
	~Rocketship();
	virtual void Launch() = 0;
	virtual Rocketship *clone() = 0;
	string getName();
	void countdown();
	char getType();

private:
	string name;
	char rocketshipType;//s d c
};

#endif