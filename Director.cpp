#include "Director.h"

Director::Director(LaunchInterface *i, BaseStation *b, SpaceStation* s) 
{
    interface = i;
    base_station = b;
    space_station = s;
    crewdragon_Bay = new CrewDragonBay();
    dragon_Bay = new DragonBay();
    starlink_Bay = new StarlinkBay();
    engineer = new RocketshipEngineer(crewdragon_Bay, dragon_Bay, starlink_Bay);
    command = new Work *[5];
    command[0] = new CreateCrewDragon(engineer, interface, crewdragon_Bay, base_station);
    command[1] = new CreateDragon(engineer, interface, dragon_Bay, base_station);
    command[2] = new CreateStarlink(engineer, interface, starlink_Bay, base_station, space_station);
    command[3] = new Backup(interface);
    command[4] = new TestLaunch(interface);
    command[5] = new OrderCargo(base_station,interface);
}
Director::~Director()
{
    delete interface;
    for (int i = 0; i < 6; i++)
        delete command[i];
    delete[] command;
    delete crewdragon_Bay;
    delete dragon_Bay;
    delete starlink_Bay;
    delete engineer;
}

void Director::makeCrewDragon()
{
    command[0]->execute();
}

void Director::makeDragon()
{
    command[1]->execute();
}

void Director::makeStarlink()
{
    command[2]->execute();
}

void Director::createBackup()
{
    command[3]->execute();
}

void Director::retrieveBackup()
{
    command[3]->undo();
}

void Director::startTestLaunch()
{
    command[4]->execute();
}

void Director::returnRocketship()
{
    command[4]->undo();
}

void Director::receiveCargo()
{
    command[5]->execute();
}

void Director::runMediator()
{
    cout<<"\nDemonstrating StarlinkSatellites communication with Stations\n";
    StarlinkCollection* SC = starlink_Bay->getRocketship();
    
    StarlinkSatellite* ss =SC->getFirstSat();
    ss->setStatus(false);
    cout<<"StarlinkSatellite: "<<ss->getName()<<" was incorrectly configured ,notifying BaseStation of this error\n";
    ss->NotifyStation();
    cout<<"Status of the StarlinkSatellites ,the BaseStation is in communication with: \n";
    map<int,bool> TempMap =SC->getCommunicationRelayBS()->getStatStatus();
    for(map<int,bool>::iterator it =TempMap.begin();it!=TempMap.end();++it)
        cout<<"name: "<<it->first<<" ,status: "<<it->second<<endl;

    cout<<"BaseStation responds by fixing configuration on StarlinkSatellite "<<ss->getName()<<endl;
    base_station->resolve(ss);
    cout<<"New status of the StarlinkSatellites ,the BaseStation is in communication with: \n";
    TempMap =SC->getCommunicationRelayBS()->getStatStatus();
    for(map<int,bool>::iterator it =TempMap.begin();it!=TempMap.end();++it)
        cout<<"name: "<<it->first<<" ,status: "<<it->second<<endl;

    cout<<"End communication demonstration\n\n";
    
}