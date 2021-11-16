#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

using namespace std;

class Rocketship {
public:
	Rocketship();
	~Rocketship();
    virtual void Launch() = 0;
};

#endif