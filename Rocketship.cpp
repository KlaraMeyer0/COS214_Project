#include "Rocketship.h"

Rocketship::Rocketship(string n)
{
    name = n;
}

Rocketship::~Rocketship() {}

string Rocketship::getName()
{
    return name;
}

void Rocketship()
{
    cout << "Starting countdown:" << endl;
    for (int i = 5; i > 0; i--)
    {
        cout << i << "..." << endl;
        _sleep(500);
    }
}