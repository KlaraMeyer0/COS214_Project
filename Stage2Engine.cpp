#include "Stage2Engine.h"

Stage2Engine::Stage2Engine() {
    engine = new VacuumEngine();
};

Stage2Engine::~Stage2Engine() {
    delete engine;
};

void Stage2Engine::TurnOn(FalconRocket* r) {
    engine->TurnOn();
};

void Stage2Engine::TurnOff(FalconRocket* r) {
    engine->TurnOff();
	//r->detach();
};