#include "FalconHeavyFactory.h"
#include "FalconHeavy.h"

FalconHeavyFactory::FalconHeavyFactory() {}
FalconHeavyFactory::~FalconHeavyFactory() {}

FalconRocket *FalconHeavyFactory::createRocket()
{
    cout << "Successfully created FalconHeavy rocket" << endl;
    return new FalconHeavy();
}