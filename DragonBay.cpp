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

void DragonBay::setName(string n, Station *s)
{
    dragon = new DragonRocketship(n);
    dragon->attachToStation(s);
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
    cout << "Load from " << dragon->getStation()->name << endl;

    bool stop = false;
    int c, idx, num;
    vector<cargo*> tempCargo;
    while (!stop)
    {
        cout << "0: Choose equipment to load" << endl;
        cout << "1: Exit" << endl;
        cin >> c;

        if (cin == 0)
        {
            dragon->getStation()->printEquipment();
            cout << "Enter the index of the type of equipment you want to load: " << endl;
            cin >> idx;
            cout << "Enter the number of equipment you want to load: " << endl;
            cin >> num;

            pair<Cargo*, int> * p = dragon->getStation()->loadEquipment(idx, num);
            for (int i = 0; i < p->second)
                tempCargo.push_back(p->first);

        }
        else
            stop = true;
    }
    dragon->attachCargo(tempCargo);

}