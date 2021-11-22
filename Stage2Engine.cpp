#include "Stage2Engine.h"

Stage2Engine::Stage2Engine() {
    engine = new VacuumEngine();
};

Stage2Engine::~Stage2Engine() {
    delete engine;
};

void Stage2Engine::TurnOn(FalconRocket* r) {
    cout << "Entering stage 2" << endl;
    engine->TurnOn();
    // add a pause?
	TurnOff(r);
};

void Stage2Engine::TurnOff(FalconRocket* r) {
    cout << "Payload is in desired orbit" << endl;
    engine->TurnOff();
};

int Stage2Engine::EngineCount() {
    return 1;
};