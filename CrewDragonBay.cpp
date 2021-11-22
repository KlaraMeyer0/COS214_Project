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
    cout << "Load from " << crew_dragon->getStation()->getName() << endl;

    bool stop = false;
    int c, idx;
    vector<Cargo*> tempCargo;
    while (!stop  && !crew_dragon->getStation()->humans.empty())
    {
        cout << "1: Choose humans to board the rocket" << endl;
        cout << "2: Skip" << endl;
        cin >> c;

        while (!cin.good())
        {
            cin.clear();
            cin.ignore(15, '\n');
            cout << "Please enter a valid index: ";
            cin >> idx;
        }
//cout << "INDEX CHOSEN IS: " << c << endl;
        if (c == 1)
        {
            crew_dragon->getStation()->printHumans();
            cout << "Enter the index of the human to board the rocket: " << endl;
            cin >> idx;

            while (!cin.good() || idx <= 0)
            {
                cin.clear();
                cin.ignore(15, '\n');
                cout << "Please enter a valid index: ";
                cin >> idx;
            }

            Cargo* h = crew_dragon->getStation()->loadHumans(idx-1);

            if (h == nullptr)
                cout << "Please enter a valid index." << endl;
            else
            {
                tempCargo.push_back(h);

                cout << h->getName() << " has boarded the rocket." << endl;
            }
        }
        else
            if (c == 2)
                stop = true;
            else
                cout << "Please choose a valid option." << endl;
    }

    stop = false;
    int num;
    while (!stop && !crew_dragon->getStation()->equipment.empty())
    {
        cout << "1: Choose equipment to load" << endl;
        cout << "2: Skip" << endl;
        cin >> c;

        while (!cin.good())
        {
            cin.clear();
            cin.ignore(15, '\n');
            cout << "Please enter a valid index: ";
            cin >> idx;
        }

        if (c == 1)
        {
            crew_dragon->getStation()->printEquipment();
            cout << "Enter the index of the type of equipment you want to load: " << endl;
            cin >> idx;
            cout << "Enter the number of equipment you want to load: " << endl;
            cin >> num;

            while (!cin.good() || idx <= 0)
            {
                cin.clear();
                cin.ignore(15, '\n');
                cout << "Please enter a valid index: ";
                cin >> idx;
            }

            while (!cin.good() || num <= 0)
            {
                cin.clear();
                cin.ignore(15, '\n');
                cout << "Please enter a valid number: ";
                cin >> num;
            }

            pair<Cargo *, int> p = crew_dragon->getStation()->loadEquipment(idx-1, num);
            if (p.second < 0)
                cout << "Please enter a valid index." << endl;
            else
            {
                for (int i = 0; i < p.second; i++)
                    tempCargo.push_back(p.first);

                cout << "Loaded " << p.second << " " << p.first->getName() << "s." << endl;
            }
        }
        else
            if (c == 2)
                stop = true;
            else
                cout << "Please choose a valid option." << endl;
    }
    crew_dragon->attachCargo(tempCargo);
}