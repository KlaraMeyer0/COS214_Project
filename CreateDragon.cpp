#include "CreateDragon.h"

CreateDragon::CreateDragon(RocketshipEngineer *e, LaunchInterface *l, DragonBay *d)
{
    engineer = e;
    launch_interface = l;
    dragon_bay = d;
}
CreateDragon::~CreateDragon() {}

void CreateDragon::execute()
{
    string name;
    cout << "Enter a name for the Dragon Rocketship: ";
    cin >> name;
    engineer->construct(1, name);
    launch_interface->addRocketship(dragon_bay->getRocketship());
    cout << "Dragon Rocketship created succesfully." << endl;
}

void CreateDragon::undo() {}