#include "CreateDragon.h"

CreateDragon::CreateDragon(RocketshipEngineer *e, LaunchInterface *l, DragonBay *d, BaseStation *s)
{
    engineer = e;
    launch_interface = l;
    dragon_bay = d;
    base_station = s;
}
CreateDragon::~CreateDragon() {}

void CreateDragon::execute()
{
    string name;
    cout << "Enter a name for the Dragon Rocketship: ";
    cin >> name;
    engineer->construct(1, name, base_station);
    launch_interface->addRocketship(dragon_bay->getRocketship());
    cout << "Dragon Rocketship created succesfully." << endl;
}

void CreateDragon::undo() {}