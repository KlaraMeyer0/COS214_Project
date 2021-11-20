#include "_9Engine.h"

_9Engine::_9Engine() {
	core = new FalconCore();
};

_9Engine::~_9Engine() {};

void _9Engine::TurnOn(FalconRocket* r) {
	core->TurnOn();
};

void _9Engine::TurnOff(FalconRocket* r) {
	core->TurnOff();
	r->attach(new Stage2Engine());
	cout << "The first stage engine has landed on the drone ship." << endl;
};
int _9Engine::EngineCount(){
	return core->getCount();
};