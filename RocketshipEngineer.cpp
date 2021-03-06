#include "RocketshipEngineer.h"

RocketshipEngineer::RocketshipEngineer(CrewDragonBay *cd, DragonBay *d, StarlinkBay *s)
{
    rb = new RocketshipBay *[3];
    rb[0] = cd;
    rb[1] = d;
    rb[2] = s;
}

RocketshipEngineer::~RocketshipEngineer()
{
    for (int i = 0; i < 3; i++)
        rb[i] = nullptr;
    rb = nullptr;
}

void RocketshipEngineer::construct(int bay, string name, BaseStation *bs, SpaceStation *ss)
{
    rb[bay]->setName(name, bs, ss);
    rb[bay]->buildBody();
    rb[bay]->buildRocket();
    rb[bay]->addCargo();
}