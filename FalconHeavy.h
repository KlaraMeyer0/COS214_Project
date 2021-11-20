#ifndef FALCONHEAVY_H
#define FALCONHEAVY_H

using namespace std;

#include "HeavyEngine.h"
#include "FalconRocket.h"

class FalconHeavy : public FalconRocket {
public:
	FalconHeavy();
	~FalconHeavy();
	FalconRocket* clone(); // Part of the Protoype DP that is used my the Memento DP to copy the Falon9
};

#endif