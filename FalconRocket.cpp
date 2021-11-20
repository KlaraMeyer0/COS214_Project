#include "FalconRocket.h"

FalconRocket::FalconRocket(){

};

FalconRocket::~FalconRocket()
{
    delete stage;
};

void FalconRocket::detach()
{
    delete stage;
};

void FalconRocket::attach(StageEngine *s)
{
    detach();
    stage = s;
};

void FalconRocket::turnOn()
{
    if (stage != 0)
        stage->TurnOn(this);
};

void FalconRocket::turnOff()
{
    if (stage != 0)
        stage->TurnOff(this);
};
StageEngine* FalconRocket::getEngine(){
    return stage;
}