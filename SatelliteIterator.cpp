#include <iostream>

using namespace std;

#include "SatelliteIterator.h"

SatelliteIterator::SatelliteIterator(StarlinkSatellite *) : head(0), current(0) {}

SatelliteIterator::SatelliteIterator(StarlinkCollection *satCol, StarlinkSatellite *sat) : head(satCol->getFirstSat()), current(sat) {}

SatelliteIterator::~SatelliteIterator() {}

SatelliteIterator SatelliteIterator::next() {
    if (this != nullptr)
    {
        this->current = this->current->next;
    }
    return *this;
}

StarlinkSatellite *SatelliteIterator::currentSatellite() {
    return current;
}

bool SatelliteIterator::equals(SatelliteIterator * s)
{
    return current == s->current;
}
