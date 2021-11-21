

using namespace std;

#include "StarlinkCollection.h"

//CONTINUE HERE
StarlinkCollection:: StarlinkCollection(string name,BaseStation* BS ,SpaceStation* SS): Rocketship(name, 's')
{
    head = 0;
    this->BS = BS;
    this->SS = SS;

    satelliteManager = new SatelliteManager(BS,SS,this);
}


StarlinkCollection::~StarlinkCollection(){
    
    //delete the list of starlinkSattelites
    StarlinkSatellite* ptr = remove();
    while(ptr !=NULL){
        delete ptr;
        ptr = remove();
    }
    head =NULL;

    delete satelliteManager;
    delete BS;
    delete SS;
    delete relayBS;
    delete relaySS;
}

void StarlinkCollection::insert(StarlinkSatellite * s)
{
    if (head == 0)
    {
        s->next = s;
        s->previous = s;
    }
    else
    {
        s->next = head;
        s->previous = head->previous;
        head->previous->next = s;
        head->previous = s;
    }

    head = s;
}

StarlinkSatellite* StarlinkCollection::remove()
{
    if (head == 0)
        return 0;
    else
        if (head->previous == head)
        {
            StarlinkSatellite *temp = head;
            head = 0;
            return temp;
        }
        else
        {
            StarlinkSatellite* temp = head->previous;
            head->previous = head->previous->previous;
            head->previous->next = head;
            return temp;
        }
}

SatelliteIterator *StarlinkCollection::begin()
{
    return new SatelliteIterator(this, head);
}

SatelliteIterator *StarlinkCollection::end()
{
    return new SatelliteIterator(this, head->previous);
}

StarlinkSatellite *StarlinkCollection::getFirstSat()
{
    return head;
}

StarlinkCollection* StarlinkCollection:: clone(){
    
    BaseStation* BScopy =BS->clone();
    SpaceStation* SScopy =SS->clone();
    FalconRocket* rocketCopy =rocket->clone();
    
    StarlinkCollection* temp = new StarlinkCollection(this->getName(),BScopy ,SScopy);
    
    temp->satelliteManager = this->satelliteManager->clone(temp);
    temp->num_B = num_B;
    temp->num_S = num_S;
    temp->head = temp->satelliteManager->getHead();
    //BS and SS 
    //BS ,SS ,relayBS and relaySS needs to be set
}

StarlinkSatellite* StarlinkCollection:: getHead(){
    return head;
}

void StarlinkCollection::setCommunicationRelayBS(CommunicationRelay* obj){
    relayBS =obj;
}

void StarlinkCollection::setCommunicationRelaySS(CommunicationRelay* obj){
    relaySS =obj;
}

int StarlinkCollection::getRockets(){
    return rocket->getEngine()->EngineCount();
}
bool StarlinkCollection::testFire(){
    rocket->turnOn();
    bool b = rocket->getState();
    rocket->turnOff();
    return b;
}
bool StarlinkCollection::testLoading(){
    
}

void StarlinkCollection::attachRocket(FalconRocket* r)
{
    rocket = r;
}


void StarlinkCollection:: setNums(int num_B ,int num_S){
    this->num_B =num_B;
    this->num_S =num_S;
}

void StarlinkCollection:: setHead(StarlinkSatellite* head){
    this->head = head;
}

void StarlinkCollection:: setSatellites(int num_B,int num_S){
    satelliteManager->setSatellites(num_B,num_S);
}