#include "FalconHeavyFactory.h"
#include "FalconHeavy.h"

FalconHeavyFactory::FalconHeavyFactory() {}
FalconHeavyFactory::~FalconHeavyFactory() {}

FalconRocket *FalconHeavyFactory::createRocket()
{
    return new FalconHeavy();
}