#include <iostream>
#include "StarlinkCollection.h"
#include "BaseStation.h"
#include "SpaceStation.h"
#include "FalconRocket.h"
using namespace std;

namespace
{
    const int num_B = 10;
    const int num_S = 10;

    BaseStation* BS = new BaseStation();
    SpaceStation* SS = new SpaceStation();
    StarlinkCollection* SCptr = new StarlinkCollection("TestStarlinkCollection",BS,SS);

    FalconRocket* rocket =	FalconRocket();
    SCptr->attachRocket(rocket);

    SCptr->setNums(num_B ,num_S);

    SCptr->setSatellites(num_B,num_S);

    StarlinkIterator* i;
    for (i = SCptr->begin(); !(i == SCptr.end()); ++i)
        cout<<i->currentSatellite()->getName<<endl;

    StarlinkCollection* SCptrCpy = SCptr->clone();

    for (i = SCptrCpy->begin(); !(i == SCptrCpy.end()); ++i)
        cout<<i->currentSatellite()->getName<<endl;

    //checing if the StarlinkCollection are viable clones
    if(SCptr->isViableClone(SCptrCpy))
        cout<<"These are viable clones"<<endl;
    else
        cout<<"These are not viable clones"<<endl;
}