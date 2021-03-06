

using namespace std;

#include "StarlinkCollection.h"

StarlinkCollection:: StarlinkCollection(string name,BaseStation* BS ,SpaceStation* SS): Rocketship(name, 's')
{
    head = 0;
    this->BS = BS;
    this->SS = SS;

    satelliteManager = new SatelliteManager(BS,SS,this);
}

StarlinkCollection:: StarlinkCollection(int, string name,BaseStation* BS ,SpaceStation* SS): Rocketship(name, 's'){
    head = 0;
    this->BS = BS;
    this->SS = SS;
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

    rocket =NULL;
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
    CommunicationRelay* relayBSclone = new CommunicationRelay(BScopy);
    BScopy->setRelay(relayBSclone);

    SpaceStation* SScopy =SS->clone();
    CommunicationRelay* relaySSclone = new CommunicationRelay(SScopy);
    SScopy->setRelay(relaySSclone);
    
    StarlinkCollection* temp = new StarlinkCollection(10,this->getName(),BScopy ,SScopy);
    
    temp->BS = BScopy;
    temp->SS = SScopy;

    temp->relaySS = relaySSclone;
    temp->relayBS = relayBSclone;

    temp->satelliteManager = this->satelliteManager->clone(temp,BScopy ,SScopy);

    temp->rocket =rocket->clone();

    temp->num_B = num_B;
    temp->num_S = num_S;
    temp->head = temp->satelliteManager->getHead();

    return temp;
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
    return rocket->getEngine()->testFire();
}

bool StarlinkCollection::testLoading(){
    return head==NULL? false:true;
}

void StarlinkCollection::attachRocket(FalconRocket* r)
{
    rocket = r;
}


void StarlinkCollection:: setHead(StarlinkSatellite* head){
    this->head = head;
}

void StarlinkCollection:: setSatellites(int num_B,int num_S){
    this->num_B =num_B;
    this->num_S =num_S;
    satelliteManager->setSatellites(num_B,num_S);
}

void StarlinkCollection::Launch(Station* ss)
{
    this->countdown();
    rocket->turnOn();

    cout<<"BaseStation: StarlinkSatellite deployed, report: \n";
    map<int ,bool> tempBSReport = BS->getSatStatus();
    for(map<int,bool>::iterator it = tempBSReport.begin();it!=tempBSReport.end();++it){
        cout<<"Name: "<<it->first<<" ,Status: "<<it->second<<endl;
    }
    
    cout<<"\nSpaceStation: StarlinkSatellite deployed, report: \n";
    map<int ,bool> tempSSReport = SS->getSatStatus();
    for(map<int,bool>::iterator it = tempSSReport.begin();it!=tempSSReport.end();++it){
        cout<<"Name: "<<it->first<<" ,Status: "<<it->second<<endl;
    }
}

bool StarlinkCollection:: isViableClone(StarlinkCollection* obj){

    if((this->num_B != obj->num_B)||(this->num_S != obj->num_S))
        return false;

    if(&(this->rocket)==&(obj->rocket))
        return false;

    if((&(this->BS) == &(obj->BS))||(&(this->SS) == &(obj->SS)))
        return false;

    if(this->SS->getSatStatus() != obj->SS->getSatStatus())
        return false;
    
    if(this->BS->getSatStatus() != obj->BS->getSatStatus())
        return false;
    
    if((this->BS->getName() != obj->BS->getName()) || (this->SS->getName() != obj->SS->getName()))
        return false;

    if(this->relayBS->getStatStatus() != obj->relayBS->getStatStatus())
        return false;
    
    if(this->relaySS->getStatStatus() != obj->relaySS->getStatStatus())
        return false;

    return true;

}

int StarlinkCollection:: getB(){
    return num_B;
}

int StarlinkCollection:: getS(){
    return num_S;
}

BaseStation* StarlinkCollection:: getBS(){
    return BS;
}

SpaceStation* StarlinkCollection:: getSS(){
    return SS;
}

CommunicationRelay* StarlinkCollection:: getCommunicationRelaySS(){
    return relaySS;
}

CommunicationRelay* StarlinkCollection::  getCommunicationRelayBS(){
    return relayBS;
}

SatelliteManager* StarlinkCollection:: getSatelliteManager(){
    return satelliteManager;
}

void StarlinkCollection::startLanding(Station* base)
{

}
Spacecraft* StarlinkCollection::getSpacecraft(){
    return nullptr;
}
FalconRocket* StarlinkCollection::getRocket(){
    return nullptr;
}
Cargo** StarlinkCollection::getCargo(){
    return nullptr;
}
void StarlinkCollection::attachSpacecraft(Spacecraft* s){}
void StarlinkCollection::attachCargo(vector<Cargo*> cvect){
    cout << "Cannot attach cargo to StarlinkCollection" <<endl;
}