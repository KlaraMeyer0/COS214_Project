#include "MerlinEngine.h"

MerlinEngine::MerlinEngine() {};

MerlinEngine::~MerlinEngine() {};

void MerlinEngine::TurnOn() {
	On = true;
	cout << "Turning on merlin engine" << endl;
};

void MerlinEngine::TurnOff() {
	On = false;
	cout << "Turning off merlin engine" << endl;
};