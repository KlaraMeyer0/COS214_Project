#ifndef FALCON9_H
#define FALCON9_H

using namespace std;

#include "_9Engine.h"
#include "FalconRocket.h"

class Falcon9 : public FalconRocket {
public:
	Falcon9();
	virtual ~Falcon9();
	FalconRocket* clone(); // Part of the Protoype DP that is used my the Memento DP to copy the Falon9
};

#endif