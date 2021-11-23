/**
 * @file StarlinkSatellite.h
 * @class StarlinkSatellite
 * @author Luca Loubser
 * @brief Design Pattern: Mediator, Participant: ConcreteMediator
 */

#ifndef COMMUNICATIONRELAY_H
#define COMMUNICATIONRELAY_H
#include <vector>
#include "StarlinkSatellite.h"
#include "Station.h"
#include <map>
using namespace std;

class StarlinkSatellite;
class Station;

class CommunicationRelay {
public:
    
    ///@param Station is a pointer to Station instanse 
	CommunicationRelay(Station*);

    /** @brief Disconnects it from the StarlinkSatellite it is associated with
    *          and removes all StarlinkSatellite* from the satellites vector
    */
    virtual	~CommunicationRelay();
    
    /**
     * @brief used to notify the Station if a StarlinkSatellite becomes non functional
     *        this is indicated by it's status being false ,the ComunicationRealy will 
     *        also keep track of this in the SatStatus map
     * @param StarlinkSatellite that becomes faulty 
    */
    void notify(StarlinkSatellite*);

    /**
     * @brief used to associate a StarlinkSatellite instance to the CommunicationRelay 
     *        allowing communication between the StarlinkSatellite and the Station ,also
     *        adds the StarlinkSatellite status and name to the map member
     * @param StarlinkSatellite that will communicate with a station
    */
    void addSatellite(StarlinkSatellite*);

    /**
     * @brief allows the Station to communicate with the StarlinkSatellite passed to the method
     * @param StarlinkSatellite that the station communicates with 
    */
    void resolve(StarlinkSatellite*);

    /**
     * @brief creates a clone of the CommunicationRelay instanse
     * @param Station the clone will be associated with ,not the same
     *                station as the one pointed to by the current instnase 
     * @return CommunicationRelay pointer
    */
    CommunicationRelay* clone(Station*);

    /**
     * @brief returs the status of the StarlinkSatellites associated with this CommunicationRelay  
     * @return map<int ,bool> that is currenlty held in the CommunicationRelay
    */
    map<int ,bool> getStatStatus();

    /**
     * @brief Returns the Station associated with this CommunicationRelay ,mainly for
     *        testing purposes
     * @return Station
    */
    Station* getRelayTo();

private:
    ///@brief Associates a colleague with a status value ,this attribute is duplicated in Station
    map<int ,bool> SatStatus;

    ///@brief Station this CommunicationRelay relays information to and from
    Station* RelayTo;

    ///@brief the StarlinkSatellite's communicating with the Station: RelayTo
    vector<StarlinkSatellite*> satellites;

};

#endif