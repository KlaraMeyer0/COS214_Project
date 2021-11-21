#include "DragonBay.h"

DragonBay::DragonBay()
{
    dragon = nullptr;
    falconheavy_factory = new FalconHeavyFactory();
    dragon_factory = new DragonFactory();
}
DragonBay::~DragonBay()
{
    delete falconheavy_factory;
    delete dragon_factory;
}

DragonRocketship *DragonBay::getRocketship()
{
    return dragon;
}

void DragonBay::setName(string n, BaseStation *bs, SpaceStation *sp)
{
    dragon = new DragonRocketship(n);
    dragon->attachToStation(bs);
}

void DragonBay::buildRocket()
{
    dragon->attachRocket(falconheavy_factory->startFactory());
}

void DragonBay::buildBody()
{
    dragon->attachSpacecraft(dragon_factory->startFactory());
}

void DragonBay::addCargo()
{
    cout << "Load from " << dragon->getStation()->getName() << endl;

    bool stop = false;
    int c, idx, num;
    vector<Cargo *> tempCargo;
    while (!stop)
    {
        cout << "0: Choose equipment to load" << endl;
        cout << "1: Exit" << endl;
        cin >> c;

        if (c == 0)
        {
            dragon->getStation()->printEquipment();
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

            pair<Cargo *, int> *p = dragon->getStation()->loadEquipment(idx, num);

            if (p == nullptr)
                cout << "Please enter a valid index." << endl;
            else
            {
                for (int i = 0; i < p->second; i++)
                    tempCargo.push_back(p->first);

                cout << "Loaded " << p->second << " " << p->first->getName() << "s." << endl;
            }
        }
        else
            if (c == 1)
                stop = true;
            else
                cout << "Please choose a valid option." << endl;
    }
    dragon->attachCargo(tempCargo);
}