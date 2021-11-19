#include "RocketshipEngineer.h"

RocketshipEngineer::RocketshipEngineer()
{
    rb = new RocketshipBay *[3];
    rb[0] = new StarlinkBay();
    rb[1] = new CrewDragonBay();
    rb[2] = new DragonBay();
}

RocketshipEngineer::~RocketshipEngineer()
{
    for (int i = 0; i < 3; i++)
        delete rb[i];
    delete[] rb;
}

void RocketshipEngineer::construct(int bay, string name)
{
    rb[bay]->setName(name);
    rb[bay]->buildBody();
    rb[bay]->buildRocket();
    rb[bay]->addCargo();
}