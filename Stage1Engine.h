#ifndef STAGE1ENGINE_H
#define STAGE1ENGINE_H

using namespace std;

class Stage1Engine {
public:
	Stage1Engine();
	~Stage1Engine();
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};

#endif