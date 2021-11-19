#ifndef FALCONHEAVY_H
#define FALCONHEAVY_H

using namespace std;

#include "HeavyEngine.h"
#include "FalconRocket.h"

class FalconHeavy : public FalconRocket {
public:
	FalconHeavy();
	~FalconHeavy();
	FalconRocket* clone();
};

#endif