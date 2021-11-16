#ifndef STAGEENGINE_H
#define STAGEENGINE_H

using namespace std;

class StageEngine {
public:
	StageEngine();
	~StageEngine();
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};

#endif