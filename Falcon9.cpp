#include "Falcon9.h"

Falcon9::Falcon9() {
    stage = new _9Engine();
};

Falcon9::~Falcon9() {};

FalconRocket* Falcon9::clone(){
    return new Falcon9();
}