#include "CreateCrewDragon.h"

CreateCrewDragon::CreateCrewDragon(RocketshipEngineer *e, LaunchInterface *l, CrewDragonBay *cd)
{
    engineer = e;
    launch_interface = l;
    crewdragon_bay = cd;
}
CreateCrewDragon::~CreateCrewDragon() {}

void CreateCrewDragon::execute()
{
    string name;
    cout << "Enter a name for the CrewDragon Rocketship: ";
    cin >> name;
    engineer->construct(0, name);
    launch_interface->addRocketship(crewdragon_bay->getRocketship());
    cout << "CrewDragon Rocketship created succesfully." << endl;
}

void CreateCrewDragon::undo() {}