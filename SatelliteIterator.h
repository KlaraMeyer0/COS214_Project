/**
 * @file SatelliteIterator.h
 * @author Klara Meyer
 *
 * @brief
 *
 * Design Pattern: Iterator
 * Participant: Iterator
 */

#ifndef SATELLITEITERATOR_H
#define SATELLITEITERATOR_H

using namespace std;

#include "StarlinkSatellite.h"
#include "StarlinkCollection.h"

class StarlinkCollection;

class SatelliteIterator
{
    public:
        /**
         * Constructor that sets the iterator to the head of the structure and the current satellite in the structure.
         *
         * @param satCol Structure to be iterated through
         * @param sat Current position of iterator
         */
        SatelliteIterator(StarlinkCollection* satCol, StarlinkSatellite* sat);

        /**
         * Destructor of the iterator
         */
        virtual ~SatelliteIterator();

        /**
         * Used to move the iterator to the next satellite in the structure
         *
         * @return The next satellite in the structure
         */
        SatelliteIterator next();

        /**
         * Used to access the current satellite in the structure
         *
         * @return The current satellite in the structure
         */
        StarlinkSatellite* currentSatellite();

        /**
         * Used to compare two SatelliteIterators
         *
         * @return boolean value indicating whether two SatelliteIterators are equal
         */
        bool equals(SatelliteIterator*);
    protected:
        /**
         * Stores the head of the structure that is being traversed by the iterator
         */
        StarlinkSatellite* head;

        /**
         * Stores satellite that the iterator is currently pointing to
         */
        StarlinkSatellite* current;
};

#endif