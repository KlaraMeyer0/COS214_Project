#include "CreateStarlink.h"

CreateStarlink::CreateStarlink(RocketshipEngineer *e, LaunchInterface *l, StarlinkBay *s, Station *station)
{
    engineer = e;
    launch_interface = l;
    starlink_bay = s;
    base_station = station;
}
CreateStarlink::~CreateStarlink() {}

void CreateStarlink::execute()
{
    string name;
    cout << "Enter a name for the Starlink Collection: ";
    cin >> name;
    engineer->construct(2, name, base_station);
    launch_interface->addRocketship(starlink_bay->getRocketship());
    cout << "Starlink Collection created succesfully." << endl;
}

void CreateStarlink::undo() {}