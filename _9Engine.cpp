#include "_9Engine.h"

_9Engine::_9Engine() {
	core = new FalconCore();
};

_9Engine::~_9Engine() {};

void _9Engine::TurnOn(FalconRocket* r) {
	cout << "Entering stage 1" << endl;
	core->TurnOn();
	// add a pause?
	TurnOff(r);
};

void _9Engine::TurnOff(FalconRocket* r) {
	cout << "The payload almost in orbit, detach Falcon Core" << endl;
	core->TurnOff();
	r->attach(new Stage2Engine());
	cout << "The first stage engine has landed on the drone ship." << endl;
	r->turnOn();
};

int _9Engine::EngineCount(){
	return core->getCount();
};

bool _9Engine::getState(){
	return core->getState();
};