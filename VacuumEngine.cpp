#include "VacuumEngine.h"

VacuumEngine::VacuumEngine() {};

VacuumEngine::~VacuumEngine() {};

void VacuumEngine::TurnOn() {
	On = true;
	cout << "Turning on vacuum engine" << endl;
};

void VacuumEngine::TurnOff() {
	On = false;
	cout << "Turning off vacuum engine" << endl;
};