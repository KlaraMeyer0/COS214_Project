

using namespace std;

#include "StarlinkCollection.h"

	
StarlinkCollection:: StarlinkCollection(string name): Rocketship(name, 's')
{
    head = 0;
    BS = new BaseStation();
    SS = new SpaceStation();
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

StarlinkSatellite *StarlinkCollection::remove()
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
    StarlinkCollection* temp = new StarlinkCollection(this->getName());
    //Falcon Rocket needs to implemnet a clone method and set to rocket of temp
    temp->numSatellites = numSatellites;
    temp->satelliteManager = this->satelliteManager->clone(temp);
    temp->num_B = num_B;
    temp->num_S = num_S;
    temp->head = temp->satelliteManager->getHead();

}
FalconRocket* StarlinkCollection::getRocket(){
    
}