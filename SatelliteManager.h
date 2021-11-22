/**
 * @file SatelliteManager.h
 * @class SatelliteManager
 * @author Luca Loubser 
 * 
 * @brief
 * Design Pattern: Prototype
 * Participant: PrototypeManager
 */

#ifndef SATELLITEMANAGER_H
#define SATELLITEMANAGER_H
#include "StarlinkSatellite.h"
#include "PointOfCommunication.h"
#include "StarlinkCollection.h"
#include <vector>
#include "SpaceStation.h"
#include "BaseStation.h"
#include <vector>
using namespace std;

class StarlinkCollection;

class SatelliteManager {
public:
    
    /**
     * @brief Constructor to create a new SatelliteManager instanse
     *        creates CommunicationRelays that will be used by StarlinkSatellites for communication with
     *        the Stations passed to this funciton and attaches them to the StarlinkCollection associated
     *        with this SatelliteManager instance ,this method also creates prototypical instanses of StarlinkSatellite
     *        from which all StarlinkSatellite created in this class will be clones ,this class employs the method 
     *        of Lazy Creation
     * @param BS is a BaseStation instance some of the created StarlinkSatellites will communicate with 
     * @param SS is a SpaceStation instance some of the created StarlinkSatellites will communicate with 
     * @param SC is a StarlinkCollection instanse that uses this SatelliteManager instanse to creaate StarlinkSatellites
    */
	SatelliteManager(BaseStation* BS ,SpaceStation* ST, StarlinkCollection* SC);
	
    /**
     * @brief Destructor that deallocates the prototypical instances used in this class
     *        and removes associations with the communicationRelays ,StarlinkCollection 
     *        ,BaseStation and SpaceStation ,this metod does not deallocate the StarlinkSatellites
     *        it has created (done in associated StarlinkCollection)
    */
    virtual ~SatelliteManager();

    /**
     * @brief Creates num_B amount of StarlinkSatellites that communicate with the BaseStation
     *        and num_S amount of StarlinkSatellites that communicate with the SpaceStation and
     *        associates them with the StarlinkCollection ,BaseStation and SpaceStation passed to 
     *        the cosntructor of this class ,in both cases using the prototypical instances 
     *        created in the construcor of this class
     * @param num_B int
     * @param num_S int
    */
    void setSatellites(int num_B, int num_S);
    

    /**
     * @brief Creates a Clone of the Given SatelliteManager ,associating it with a 
     *        new StarlinkCollection, BaseStation and SpaceStation passed as parameters 
     *        to the method
     * @param objcopy is a StarlinkCollection pointer
     * @param BScopy is a BaseStation pointer
     * @param SScopy is a SpaceStation pointer
     * @return SatelliteManager pointer
     */
    SatelliteManager* clone(StarlinkCollection* objcopy,BaseStation* BScopy ,SpaceStation* SScopy);

    /**
     * @brief Returns the CommunicationRelay used by StarlinkSatellite tp communicate
     *        with a BaseStation
     * @return CommunicationRelay pointer
     */
    CommunicationRelay* getCommunicationRelayBS();

    /**
     * @brief Returns the CommunicationRelay used by StarlinkSatellite tp communicate
     *        with a SpaceStation
     * @return CommunicationRelay pointer
    */
    CommunicationRelay* getCommunicationRelaySS();

    /**
     * @brief Returns the StarlinkSatellite at the head of the Linked List of 
     *        StarlinkSatellites created using the SatelliteManager
     * @return StarlinkSatellite pointer
    */
    StarlinkSatellite* getHead();

    ///@return BaseStation ,returns BS member
    BaseStation* getBaseStation();

    ///@return SpaceStation ,returns SS member
    SpaceStation* getSpaceStation();

private:

    /**
     * @brief set after creation in this class and point to the First StarlinkSatellite in 
     *        the Linked List Created in the SatelliteManager
     */
    StarlinkSatellite* head;
    
    /**
     * @brief set in creation of this class ,StarlinkSatellite used to create all        
     * StarlinkSatellites that communicate with a BaseStation
    */
    StarlinkSatellite* protoBSSatellite;
    
    /**
     * @brief set in creation of this class ,StarlinkSatellite used to create all        
     * StarlinkSatellites that communicate with a SpaceStation
    */
    StarlinkSatellite* protoSTSatellite;
    
    ///@brief set in creation of this class ,used by StarlinkSatellites to communicate with a BaseStation
    CommunicationRelay* relayBS;

    ///@brief set in creation of this class ,used by StarlinkSatellites to communicate with a SpaceStation
    CommunicationRelay* relaySS;

    /**
     * @brief set in the cosntructor of this class ,this is the StarlinkCollection that
     *        uses this SatelliteManager to Create StarlinkSatellites
    */
    StarlinkCollection* SC;
    
    /**
     * @brief set in the cosntructor of this class ,this is the BaseStation that some 
     *        StarlinkSatellites created in this class communicates with
    */
    BaseStation* BS;

    /**
     * @brief set in the cosntructor of this class ,this is the SpaceStation that some 
     *        StarlinkSatellites created in this class communicates with
    */
    SpaceStation* SS;
};

#endif