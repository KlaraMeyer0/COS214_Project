#include "DragonRocketship.h"

DragonRocketship::DragonRocketship(string n) : Rocketship(n, 'd')
{

    cargo = nullptr;
    spacecraft = nullptr;
    rocket = nullptr;
}

DragonRocketship::~DragonRocketship()
{
    if (cargo != nullptr)
    {
        if (spacecraft != nullptr)
            for (int i = 0; i < spacecraft->getCapacity(); i++)
                cargo[i] = nullptr;
        delete[] cargo;
    }
}

void DragonRocketship::Launch(Station *ss)
{
    this->countdown();
    rocket->turnOn();
    this->attachToStation(ss);
    this->dropCargo();
}

Rocketship *DragonRocketship::clone()
{
    DragonRocketship *temp = new DragonRocketship(this->getName());
    temp->setSpacecraft((this->getSpacecraft())->clone());
    temp->setRocket((this->getRocket())->clone());
    if (this->getCargo() != nullptr)
    {
        Cargo** c = new Cargo*[temp->getSpacecraft()->getCapacity()];
        for (int i=0; i<this->getSpacecraft()->getCapacity(); i++)
        {
            c[i] = this->getCargo()[i]->clone();
        }
        temp->setCargo(c);
    }
    return temp;
}

void DragonRocketship::attachSpacecraft(Spacecraft *s)
{
    spacecraft = s;
}

void DragonRocketship::attachRocket(FalconRocket *r)
{
    rocket = r;
}

void DragonRocketship::attachCargo(vector<Cargo *> cvect)
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

void DragonRocketship::dropCargo()
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

int DragonRocketship::getRockets()
{
    return rocket->getEngine()->EngineCount();
}

bool DragonRocketship::testFire()
{
    return rocket->getEngine()->testFire();
}

bool DragonRocketship::testLoading()
{
    return cargo == NULL ? false : true;
}

void DragonRocketship::startLanding(Station *base)
{
    Station *s = this->getStation();
    cout << "Landing for " << this->getName() << " initialised" << endl;
    bool loopBack;
    loopBack = false;
    string response;
    string addOn;
    vector<Cargo*> temp;
    do
    {
        loopBack = false;
        cout << "Do you want to load " << addOn << "equipment from the space station? (Y/N):";
        cin >> response;
        if (response == "Y")
        {
            if (!s->equipment.empty())
            {
                int index;
                int amount;
                cout << "Choose an index from the list:" << endl;
                s->printEquipment();
                cin >> index;

                while (!cin.good() || index <= 0)
                {
                    cin.clear();
                    cin.ignore(15, '\n');
                    cout << "Please enter a valid index: ";
                    cin >> index;
                }

                cout << "How many " << s->equipment.at(index-1).first->getName() << " do you want to load";
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
    this->attachCargo(temp);
    cout << this->getName() << " begins its journey back to earth" << endl;
    this->attachToStation(base);
}
Spacecraft* DragonRocketship::getSpacecraft(){
    return spacecraft;
}
FalconRocket* DragonRocketship::getRocket(){
    return rocket;
}
Cargo** DragonRocketship::getCargo(){
    return cargo;
}
void DragonRocketship::setSpacecraft(Spacecraft* s){
    spacecraft = s;
}
void DragonRocketship::setRocket(FalconRocket* r){
    rocket = r;
}
void DragonRocketship::setCargo(Cargo** c){
    cargo = c;
}