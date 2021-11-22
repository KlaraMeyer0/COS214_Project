/**
 * @file CommunicationRelay.h
 * @class CommunicationRelay
 * @author {Luca Loubser ,Klara Meyer}
 * 
 * @brief
 * Design Pattern: Mediator, Prototype
 * Participant: ConcreteColleague, ConcretePrototype
 * CommunicationRelay inherits from PointOfCommunication
 */

#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

using namespace std;

#include "PointOfCommunication.h"
#include "CommunicationRelay.h"
#include <string>
#include <iostream>

class CommunicationRelay;

class StarlinkSatellite : public PointOfCommunication{
public:
    /**
     * @brief Creates a new StarlinkSatellite instance ,calls the base class
     *        constructor to set the name of the StarlinkSatellite instance
     *        sets relay ,next and previous to NULL
     * @param communicatesWith string that serves to indicate the Station 
     *        instance the StarlinkSatellite communicates with through the
     *        CommunicationRelay
     * @param obj CommunicationRelay instance that the StarlinkSatellite
     *            instance communicates with
     */
	StarlinkSatellite(string communicatesWith, CommunicationRelay* obj);
	
    ///@brief defualt constructor used in the cloneExact method
    StarlinkSatellite();

    /**
     * @brief Destructor for the StarlinkSatellite instance that removes all
     *        associations to other StarlinkSatellite instance and the
    */
    virtual ~StarlinkSatellite();


    ///@return string representing the Station the StarlinkSatellite instance communicates with
    string getCommunicatesWith();

    /** 
     * @return StarlinkSatellite pointer that is a clone of this StarlinkSatellite instance
     *          the names of the StarlinkSatellite will differ
    */
    StarlinkSatellite* clone();

    /** 
     * @return StarlinkSatellite pointer that is a clone of this StarlinkSatellite instance
     *         with the same name as the calling object
    */
    StarlinkSatellite* cloneExact(string communicatesWith, CommunicationRelay* obj);

    ///@brief Used in the Iterator Pattern ,points to StarlinkSatellite instance ,set in creation process
    StarlinkSatellite* next;

    ///@brief Used in the Iterator Pattern ,points to StarlinkSatellite instance ,set in creation process
    StarlinkSatellite* previous;

private:

    ///@brief CommunicationRelay instance
    CommunicationRelay* relay;
    
    ///@brief {BaseStation,SpaceStation}  
    string communicatesWith;  
};

#endif