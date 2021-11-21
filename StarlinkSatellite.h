/**
 * @file CommunicationRelay.h
 * @class CommunicationRelay
 * @author Luca Loubser ,Klara Meyer
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

class CommunicationRelay;

class StarlinkSatellite : public PointOfCommunication{
public:
    /**
     * @brief Creates a new StarlinkSatellite instanse ,calls the base class
     *        constructor to set the name of the StarlinkSatellite instanse
     *        sets relay ,next and previous to NULL
     * @param communicatesWith string that serves to indicate the Station 
     *        instanse the StarlinkSatellite communicates with through the  
     *        CommunicationRelay
     * @param obj CommunicationRelay instanse that the StarlinkSatellite
     *            instanse communicates with 
     */
	StarlinkSatellite(string communicatesWith, CommunicationRelay* obj);
	
    /**
     * @brief Destructor for the StarlinkSatellite instanse that removes all 
     *        associations to other StarlinkSatellite instanse and the
    */
    virtual ~StarlinkSatellite();


    ///@return string representing the Station the StarlinkSatellite instanse communicates with 
    string getCommunicatesWith();

    /** 
     * @return StarlinkSatellite pointer that is a clone of this StarlinkSatellite instanse
     *          the names of the StarlinkSatellite will differ
    */
    StarlinkSatellite* clone();

    /** 
     * @return StarlinkSatellite pointer that is a clone of this StarlinkSatellite instanse
     *         with the same name as the calling object
    */
    StarlinkSatellite* cloneExact(string communicatesWith, CommunicationRelay* obj);

    ///@brief Used in the Iterator Pattern ,points to StarlinkSatellite instanse
    StarlinkSatellite* next;
    StarlinkSatellite* previous;

private:

    ///@brief CommunicationRelay instanse
    CommunicationRelay* relay;
    
    ///@brief {BaseStation,SpaceStation}  
    string communicatesWith;  
};

#endif