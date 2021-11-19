#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

using namespace std;

class Rocketship
{
public:
	Rocketship();
	~Rocketship();
	virtual void Launch() = 0;
	virtual Rocketship *clone() = 0;
	string getName() { return name; };

private:
	string name;
};

#endif