#ifndef ENGINE_H
#define ENGINE_H

using namespace std;

class Engine {
protected:
	bool On; // Variable storing weither the engine is on or not
public:
	Engine();
	virtual ~Engine();
	virtual void TurnOn() = 0; // Turn on the engine
	virtual void TurnOff() = 0; // Turn off the engine
	virtual bool getState();
};

#endif