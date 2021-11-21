#include "FalconCore.h"

FalconCore::FalconCore() {
	merlins = new MerlinEngine*[EngineCount];

	for (int i = 0; i < EngineCount; i++) {
		merlins[i] = new MerlinEngine();
	};
};

FalconCore::~FalconCore() {
	for (int i = 0; i < EngineCount; i++) {
		delete merlins[i];
	}
	delete [] merlins;
};

void FalconCore::TurnOn() {
	On = true;
	cout << "Turning on Falcon Core" << endl;
	for (int i = 0; i < EngineCount; i++) {
		merlins[i]->TurnOn();
	}
	cout << "All merlin engines are firing" <<endl;
};

void FalconCore::TurnOff() {
	On = false;
	cout << "Turning off Falcon Core" << endl;
	for (int i = 0; i < EngineCount; i++) {
		merlins[i]->TurnOff();
	}
	cout << "All merlin engines are off";
};
int FalconCore::getCount(){
	return EngineCount;
}