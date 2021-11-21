/**
 * @file StarlinkCollection.h
 * @class StarlinkCollection
 * @author Luca Loubser
 * 
 * @brief
 * StarlinkCollection inherits from Rocketship
 * Design Pattern: Prototype
 * Participant: Client
 */

#ifndef STARLINKCOLLECTION_H
#define STARLINKCOLLECTION_H

using namespace std;

#include "StarlinkSatellite.h"
#include "SatelliteManager.h"
#include "Rocketship.h"
#include "SatelliteIterator.h"
#include <vector>
#include "BaseStation.h"
#include "SpaceStation.h"

class SatelliteManager;
class SatelliteIterator;

class StarlinkCollection : public Rocketship {
public:

    /**
     * @brief Creates a new instanse of a StarlinkCollection 
     *        creates a satelliteManager and sets satelliteManager.
     * @param name string name of the StarlinkCollection
     * @param SS BaseStation some StarlinkSatellite communicate with
     * @param BS BaseStation some StarlinkSatellite communicate with
     */
    StarlinkCollection(string name,BaseStation* BS ,SpaceStation* SS); 
	
    /**
     * @brief Deallocates all members associated with the StarlinkCollection ,bar
     *        the FalconRocket instance 
     */
    virtual ~StarlinkCollection();

    void Launch();
    virtual int getRockets();
    virtual bool testFire();
    virtual bool testLoading();

    //Used by the Iterator Design Pattern
    void insert(StarlinkSatellite*);
    StarlinkSatellite* remove();
    SatelliteIterator* begin();
    SatelliteIterator* end();
    StarlinkSatellite* getFirstSat();
    
    /**
     * @brief Creates a clone of the StarlinkCollection ,creating deep
     *        coppies of all its members
     * @return StarlinkCollection
    */
    StarlinkCollection* clone();
    
    /**
     * @brief Sets the FalconRocket attribute
     * @param FalconRocket
    */
    void attachRocket(FalconRocket*);

    /**
     * @brief Sets the CommunicationRelay the StarlinkSatellite that communicate with
     *        the BaseStation communicates through
     * @param CommunicationRelay
    */
    void setCommunicationRelayBS(CommunicationRelay*);

    /**
     * @brief Sets the CommunicationRelay the StarlinkSatellite that communicate with
     *        the SpaseStation communicates through
     * @param CommunicationRelay
    */
    void setCommunicationRelaySS(CommunicationRelay*);

    /**
     * @brief Sets the number of StarlinkSatellite that communicate with a BaseStation
     *        and the SpaceStation respctively 
     * @param num_B
     * @param num_S
    */
    void setNums(int num_B ,int num_S);

    /**
     * @brief Sets the head attribute
     * @param StarlinkSatellite
    */
    void setHead(StarlinkSatellite* head);

    /**
     * @brief Calls the setSatellites(int, int) method on the satelliteManager
     *        to create the StarlinkSatellites
     * @param num_B int
     * @param num_S int
     */
    void setSatellites(int num_B,int num_S);

    /**
     * @brief Returns true if the passed in parameter is a deep copy 
     *        of the calling object ,this function is used for testing purposes only
     * @param StarlinkCollection
     */
    bool isViableClone(StarlinkCollection*);

private:

    ///@brief Set in the StarlinkBay
    ///@brief num_B is the number of StarlinkSattelites that communicate with a BaseStation 
    int num_B;
    ///@brief num_S is the number of StarlinkSattelites that communicate with a SpaceStation
    int num_S;
    ///@brief Is the rocket this StarlinkCollection is associated with
    FalconRocket* rocket;
    
    ///@brief Created in Client and assigned in constructor
    ///@brief BaseStation the StarlinkCollection is associated with
    BaseStation* BS;
    ///@brief BaseStation the StarlinkCollection is associated with
    SpaceStation* SS;

    ///@brief Created in this class ,SatelliteManager used to create StarlinkSatellites
    SatelliteManager* satelliteManager;

    ///@brief Created and assigned in the SatelliteManager
    /**
     * @brief CommunicationRelay the StarlinkCollection is associated with 
     * used for commuincation between StarlinkSatellites and the BaseStation
     */
    CommunicationRelay* relayBS;
    /**
     * @brief CommunicationRelay the StarlinkCollection is associated with 
     * used for commuincation between StarlinkSatellites and the BaseStation
     */
    CommunicationRelay* relaySS;
    ///@brief pointer to StarlinkSatellites linked list created uisng the SatelliteManager  
    StarlinkSatellite* head;

};

#endif