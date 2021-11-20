

using namespace std;

#include "StarlinkCollection.h"
	
StarlinkCollection:: StarlinkCollection(string name): Rocketship(name)
{
    head = 0;
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
    return nullptr;
}

SatelliteIterator *StarlinkCollection::end()
{
    return nullptr;
}
