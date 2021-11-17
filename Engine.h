#ifndef ENGINE_H
#define ENGINE_H

using namespace std;

class Engine {
protected:
	bool On;
public:
	Engine();
	~Engine();
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};

#endif