#include "HeavyEngine.h"

HeavyEngine::HeavyEngine() {
	cores = new FalconCore*[3];

	for (int i = 0; i < 3; i++) {
		cores[i] = new FalconCore();
	}
};

HeavyEngine::~HeavyEngine() {
	for (int i = 0; i < 3; i++) {
		delete cores[i];
	}
	delete [] cores;
};

void HeavyEngine::TurnOn(FalconRocket* r) {
	cout << "Entering stage 1" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Turning on Falcon Core " << i+1 << ":" << endl;
		cores[i]->TurnOn();
	}
	// add a pause?
	TurnOff(r);
};

void HeavyEngine::TurnOff(FalconRocket* r) {
	cout << "The payload almost in orbit, detach Falcon Cores" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Turning off Falcon Core " << i+1 << ":" << endl;
		cores[i]->TurnOff();
	}
	r->attach(new Stage2Engine());
	r->turnOn();
	// add a pause?
	cout << "The first stage engine has landed on the drone ship." << endl;
};

int HeavyEngine::EngineCount() {
	return cores[0]->getCount() + cores[1]->getCount() + cores[2]->getCount();
};

bool HeavyEngine::getState() {
	return cores[0]->getState() & cores[1]->getState() & cores[2]->getState();
};