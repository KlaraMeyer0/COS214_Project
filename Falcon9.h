#ifndef FALCON9_H
#define FALCON9_H

using namespace std;

#include "_9Engine.h"
#include "FalconRocket.h"

class Falcon9 : public FalconRocket {
public:
	Falcon9();
	~Falcon9();
	FalconRocket* clone();
};

#endif