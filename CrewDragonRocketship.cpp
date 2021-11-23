#include "CrewDragonRocketship.h"

using namespace std;

CrewDragonRocketship::CrewDragonRocketship(string n) : Rocketship(n, 'c')
{
    cargo = nullptr;
    spacecraft = nullptr;
    rocket = nullptr;
}

CrewDragonRocketship::~CrewDragonRocketship()
{
    if (cargo != nullptr)
    {
        if (spacecraft != nullptr)
            for (int i = 0; i < spacecraft->getCapacity(); i++)
                cargo[i] = nullptr;
        delete[] cargo;
    }
}

void CrewDragonRocketship::Launch(Station *ss)
{
    this->countdown();
    rocket->turnOn();
    this->attachToStation(ss);
    this->dropCargo();
}

Rocketship *CrewDragonRocketship::clone()
{
    CrewDragonRocketship *temp = new CrewDragonRocketship(this->getName());
    temp->attachSpacecraft((this->getSpacecraft())->clone());
    temp->attachRocket((this->getRocket())->clone());
    if (this->getCargo() == nullptr)
    {
        vector<Cargo*> c;
        for (int i=0; i<this->getSpacecraft()->getCapacity(); i++)
        {
            c.push_back(this->getCargo()[i]->clone());
        }
        temp->attachCargo(c);
    }
    return temp;
}

void CrewDragonRocketship::attachSpacecraft(Spacecraft *s)
{
    spacecraft = s;
}

void CrewDragonRocketship::attachRocket(FalconRocket *r)
{
    rocket = r;
}

void CrewDragonRocketship::attachCargo(vector<Cargo *> cvect)
{
    cargo = new Cargo *[spacecraft->getCapacity()];
    int toFill = cvect.size();
    if (toFill > spacecraft->getCapacity())
    {
        cout << "There is not enough space on the " << this->getName() << " for all the cargo" << endl;
        toFill = spacecraft->getCapacity(); // only fill the available space
    }
    for (int i = 0; i < toFill; i++)
        cargo[i] = cvect[i];
}

void CrewDragonRocketship::dropCargo()
{
    Station *station = this->getStation();
    if (cargo[0] == NULL)
        cout << "There is no Cargo to unlaod" << endl;
    for (int i = 0; i < spacecraft->getCapacity(); i++)
    {
        if (cargo[i] != NULL)
        {
            station->receiveCargo(cargo[i]);
            cargo[i] = NULL;
        }
    }
}

int CrewDragonRocketship::getRockets()
{
    return rocket->getEngine()->EngineCount();
}

bool CrewDragonRocketship::testFire()
{
    return rocket->getEngine()->testFire();
}

bool CrewDragonRocketship::testLoading()
{
    return cargo == NULL ? false : true;
}

void CrewDragonRocketship::startLanding(Station *base)
{
    Station *s = this->getStation();
    bool loopBack;
    loopBack = false;
    string response;
    string addOn;
    vector<Cargo *> temp;
    cout << "Landing for " << this->getName() << " initialised" << endl;
    // cargo loop
    do
    {
        loopBack = false;
        cout << "Do you want to load " << addOn << "equipment from the space station? (Y/N): ";
        cin >> response;
        if (response == "Y")
        {
            if (!s->equipment.empty())
            {
                int index;
                int amount;
                cout << "Choose an index from the list: " << endl;
                s->printEquipment();
                cin >> index;

                while (!cin.good() || index <= 0)
                {
                    cin.clear();
                    cin.ignore(15, '\n');
                    cout << "Please enter a valid index: ";
                    cin >> index;
                }

                cout << "How many " << s->equipment.at(index - 1).first->getName() << "s do you want to load";
                cin >> amount;

                while (!cin.good() || amount <= 0)
                {
                    cin.clear();
                    cin.ignore(15, '\n');
                    cout << "Please enter a valid amount: ";
                    cin >> amount;
                }

                pair<Cargo *, int> p = s->loadEquipment(index - 1, amount);

                if (p.second < 0)
                    cout << "Please enter a valid index." << endl;
                else
                {
                    for (int i = 0; i < p.second - 1; i++)
                    {
                        temp.push_back(p.first->clone());
                    }
                    temp.push_back(p.first);
                }

                loopBack = true;
                addOn = "more ";
            }
            else
            {
                cout << "No equipment to load" << endl;
                loopBack = false;
            }
        }
        else if (response != "N")
        {
            cout << "Please input only Y or N." << endl;
            loopBack = true;
        }
    } while (loopBack);
    // human loop
    addOn = "";
    do
    {
        cout << "Do you want to board " << addOn << "humans from the space station? (Y/N): ";
        cin >> response;
        if (response == "Y")
        {
            if (!s->humans.empty())
            {
                int index;
                int amount;
                cout << "Choose an index from the list: " << endl;
                s->printHumans();
                cin >> index;

                while (!cin.good() || index <= 0)
                {
                    cin.clear();
                    cin.ignore(15, '\n');
                    cout << "Please enter a valid index: ";
                    cin >> index;
                }

                Cargo *c = s->loadHumans(index - 1);

                if (c == nullptr)
                    cout << "Please enter a valid index." << endl;
                else
                    temp.push_back(c);

                loopBack = true;
                addOn = "more ";
            }
            else
            {
                cout << "No humans to board" << endl;
                loopBack = false;
            }
        }
        else if (response != "N")
        {
            cout << "Please input only Y or N. " << endl;
            loopBack = false;
        }
    } while (loopBack);
    this->attachCargo(temp);
    cout << this->getName() << " begins its journey back to earth" << endl;
    this->attachToStation(base);
}
Spacecraft* CrewDragonRocketship::getSpacecraft(){
    return spacecraft;
}
FalconRocket* CrewDragonRocketship::getRocket(){
    return rocket;
}
Cargo** CrewDragonRocketship::getCargo(){
    return cargo;
}