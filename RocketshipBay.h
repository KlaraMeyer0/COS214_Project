#ifndef ROCKETSHIPBAY_H
#define ROCKETSHIPBAY_H

using namespace std;

class RocketshipBay
{
public:
	RocketshipBay();
	~RocketshipBay();
	virtual void setName(string n, Station *s) = 0;
	virtual void buildRocket() = 0;
	virtual void buildBody() = 0;
	virtual void addCargo() = 0;
};

#endif