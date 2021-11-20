#include <iostream>

using namespace std;

#include "SatelliteIterator.h"

SatelliteIterator::SatelliteIterator(StarlinkSatellite *) : head(0), current(0) {}

SatelliteIterator::SatelliteIterator(StarlinkCollection *satCol, StarlinkSatellite *sat) : head(satCol->getFirstSat()), current(sat) {}

SatelliteIterator::~SatelliteIterator() {}

StarlinkSatellite *SatelliteIterator::next() {
    if (this != nullptr)
    {
        this->current = this->current->next;
    }
}

StarlinkSatellite *SatelliteIterator::currentSatellite() {
    return current;
}


