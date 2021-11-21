#include "Engine.h"

Engine::Engine() {
    On = false;
};

Engine::~Engine() {};

bool Engine::getState(){
    return On;
}