#include "FalconRocket.h"

FalconRocket::FalconRocket() {

};

FalconRocket::~FalconRocket() {
    delete stage;
};

void detach() {
    delete stage;
};

void attach(StageEngine* s) {
    stage = s;
};

void FalconRocket::turnOn() {
    if (stage != 0) stage->TurnOn(this);
};

void FalconRocket::turnOff() {
    if (stage != 0) stage->TurnOff(this);
};