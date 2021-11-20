#include "CreateCrewDragon.h"

CreateCrewDragon::CreateCrewDragon(RocketshipEngineer *e, LaunchInterface *l, CrewDragonBay *cd, Station* s)
{
    engineer = e;
    launch_interface = l;
    crewdragon_bay = cd;
    base_station = s;
}
CreateCrewDragon::~CreateCrewDragon() {}

void CreateCrewDragon::execute()
{
    string name;
    cout << "Enter a name for the CrewDragon Rocketship: ";
    cin >> name;
    engineer->construct(0, name, base_station);
    launch_interface->addRocketship(crewdragon_bay->getRocketship());
    cout << "CrewDragon Rocketship created succesfully." << endl;
}

void CreateCrewDragon::undo() {}