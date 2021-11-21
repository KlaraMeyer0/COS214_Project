#include "BaseStation.h"
#include "SpaceStation.h"
#include "LaunchInterface.h"
#include "Director.h"

int main()
{
    BaseStation *base_station = new BaseStation();
    SpaceStation *space_station = new SpaceStation();
    LaunchInterface *launch_interface = new LaunchInterface();
    Director *Bob = new Director(launch_interface, base_station, space_station);
    Bob->receiveCargo();
    Bob->makeCrewDragon();
    Bob->startTestLaunch();
    return 0;
}
