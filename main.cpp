#include "BaseStation.h"
#include "SpaceStation.h"
#include "LaunchInterface.h"
#include "Director.h"
#include <map>
using namespace std;

int main()
{
    BaseStation *base_station = new BaseStation();
    SpaceStation *space_station = new SpaceStation();
    LaunchInterface *launch_interface = new LaunchInterface(space_station, base_station);
    Director *Bob = new Director(launch_interface, base_station, space_station);
    cout<<"Phase 1"<<endl;
    Bob->receiveCargo();
    Bob->makeCrewDragon();
    Bob->makeDragon();
    Bob->makeStarlink();
    Bob->startTestLaunch();
    Bob->returnRocketship();
    Bob->runMediator();
    cout<<"Phase 2"<<endl;
    Bob->createBackup();
    Bob->makeStarlink();
    Bob->startTestLaunch();
    Bob->returnRocketship();
    Bob->runMediator();
    Bob->retrieveBackup();
    Bob->startTestLaunch();
    Bob->returnRocketship();
    
    return 0;
}
