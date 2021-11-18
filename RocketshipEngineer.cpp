#include "RocketshipEngineer.h"

RocketshipEngineer::RocketshipEngineer() {}
RocketshipEngineer::~RocketshipEngineer() {}

void RocketshipEngineer::construct(int bay)
{
    rb[bay]->buildBody();
    rb[bay]->addCargo();
    rb[bay]->buildRocket();
}