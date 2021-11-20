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
	for (int i = 0; i < 3; i++) {
		cores[i]->TurnOn();
	}
};

void HeavyEngine::TurnOff(FalconRocket* r) {
	for (int i = 0; i < 3; i++) {
		cores[i]->TurnOff();
	}
	r->attach(new Stage2Engine());
	cout << "The first stage engine has landed on the drone ship." << endl;
};
int HeavyEngine::EngineCount(){
	return cores[0]->getCount() + cores[1]->getCount() + cores[2]->getCount();
}
bool HeavyEngine::getState(){
	return cores[0]->getState() & cores[1]->getState() & cores[2]->getState();
}