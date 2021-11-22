#include "Falcon9Factory.h"
#include "Falcon9.h"

Falcon9Factory::Falcon9Factory() {}
Falcon9Factory::~Falcon9Factory() {}

FalconRocket *Falcon9Factory::createRocket()
{
    cout << "Successfully created Falcon9 rocket" << endl;
    return new Falcon9();
}