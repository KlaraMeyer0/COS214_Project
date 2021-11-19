#include "FalconHeavy.h"

FalconHeavy::FalconHeavy() {
    stage = new HeavyEngine();
};

FalconHeavy::~FalconHeavy() {};

FalconRocket* FalconHeavy::clone(){
    return new FalconHeavy();
}