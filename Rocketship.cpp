
#include "Rocketship.h"

Rocketship::Rocketship(string n, char t)
{
    name = n;
    rocketshipType = t;
}

Rocketship::~Rocketship() {}

string Rocketship::getName()
{
    return name;
}

void Rocketship::countdown()
{
    cout << "Starting countdown:" << endl;
    for (int i = 5; i > 0; i--)
    {
        cout << i << "..." << endl;
        sleep(1);
    }
}

char Rocketship::getType()
{
    return rocketshipType;
}

void Rocketship::attachToStation(Station *s)
{
    current_Station = s;
}

Station* Rocketship::getStation()
{
    return current_Station;
}