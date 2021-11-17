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
};