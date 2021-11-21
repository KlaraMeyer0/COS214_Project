#include "CrewDragonBay.h"

CrewDragonBay::CrewDragonBay()
{
    crew_dragon = nullptr;
    falconheavy_factory = new FalconHeavyFactory();
    crewdragon_factory = new CrewDragonFactory();
}
CrewDragonBay::~CrewDragonBay()
{
    delete falconheavy_factory;
    delete crewdragon_factory;
}

CrewDragonRocketship *CrewDragonBay::getRocketship()
{
    return crew_dragon;
}

void CrewDragonBay::setName(string n, BaseStation *bs, SpaceStation *sp)
{
    crew_dragon = new CrewDragonRocketship(n);
    crew_dragon->attachToStation(bs);
}

void CrewDragonBay::buildRocket()
{
    crew_dragon->attachRocket(falconheavy_factory->startFactory());
}

void CrewDragonBay::buildBody()
{
    crew_dragon->attachSpacecraft(crewdragon_factory->startFactory());
}

void CrewDragonBay::addCargo()
{
    cout << "Load from " << crew_dragon->getStation()->name << endl;

    bool stop = false;
    int c, idx;
    vector<Cargo*> tempCargo;
    while (!stop)
    {
        cout << "0: Choose humans to board the rocket" << endl;
        cout << "1: Exit" << endl;
        cin >> c;

        if (c == 0)
        {
            crew_dragon->getStation()->printEquipment();
            cout << "Enter the index of the human to board the rocket: " << endl;
            cin >> idx;

            Cargo* h = crew_dragon->getStation()->loadHumans(idx);
            tempCargo.push_back(h);

            cout << h->getName() << "has boarded the rocket." << endl;
        }
        else
            stop = true;
    }

    stop = false;
    int num;
    while (!stop)
    {
        cout << "0: Choose equipment to load" << endl;
        cout << "1: Exit" << endl;
        cin >> c;

        if (c == 0)
        {
            crew_dragon->getStation()->printEquipment();
            cout << "Enter the index of the type of equipment you want to load: " << endl;
            cin >> idx;
            cout << "Enter the number of equipment you want to load: " << endl;
            cin >> num;

            pair<Cargo *, int> *p = crew_dragon->getStation()->loadEquipment(idx, num);
            for (int i = 0; i < p->second; i++)
                tempCargo.push_back(p->first);

            cout << "Loaded " << p->second << " " << p->first->getName() << "s." << endl;
        }
        else
            stop = true;
    }
    crew_dragon->attachCargo(tempCargo);
}