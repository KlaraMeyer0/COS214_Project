#ifndef FALCONROCKET_H
#define FALCONROCKET_H

using namespace std;

#include "Stage1Engine.h"
#include "Stage2Engine.h"

class FalconRocket {
private:
	Stage1Engine* stage1;
	Stage2Engine* stage2;
public:
	FalconRocket();
	~FalconRocket();
	virtual void detach() = 0;
	virtual void attach() = 0;
};

#endif