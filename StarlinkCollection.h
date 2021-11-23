/**
 * @file StarlinkCollection.h
 * @class StarlinkCollection
 * @author {Luca Loubser ,Klara Meyer}
 * @brief StarlinkCollection inherits from Rocketship, Design Pattern: Prototype, Participant: Client
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
     * @brief Creates a new instance of a StarlinkCollection
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

    /**
     * @brief Launches the Starlink collection into space and deploys and starts the starlink satellites
     * 
     * @param ss Space station with which the starlink satellites communicate
     */
    void Launch(Station* ss);
    /**
     * @brief Returns the rocket, in this case a Falcon9 rocket
     * 
     * @return int 
     */
    virtual int getRockets();
    /**
     * @brief Returns if cargo has been loaded or not
     * 
     * @return true 
     * @return false 
     */
    virtual bool testFire();
    /**
     * @brief Returns if the head is null or not
     * 
     * @return true 
     * @return false 
     */
    virtual bool testLoading();

    /**
     * @brief Used to insert a new StarlinkSatellite instance into the List of
     *        StarlinkSatellite this class has a pointer to 
     * @param StarlinkSatellite to add to the List of StarlinkSatellite
    */
    void insert(StarlinkSatellite*);

    /**
     * @brief Used to remove a StarlinkSatellite from the List of StarlinkSatellite
     *        this class has a pointer to ,removes the first StarlinkSatellite
     *        in the List
     * @param StarlinkSatellite pointer to the StarlinkSatellite that has been removed
    */
    StarlinkSatellite* remove();

    /**
     * @brief returns a SatelliteIterator that has a pointer to the first 
     *        element in the List of StarlinkSatellites 
     * @return SatelliteIterator pointer
     */
    SatelliteIterator* begin();

    /**
     * @brief returns a SatelliteIterator that has a pointer to the last 
     *        element in the List of StarlinkSatellites 
     * @return SatelliteIterator pointer
     */
    SatelliteIterator* end();

    /**
     * @brief returns a StarlinkSatellite pointing to the first 
     *        element in the List of StarlinkSatellites 
     * @return SatelliteIterator pointer
    */
    StarlinkSatellite* getFirstSat();
    
    /**
     * @brief Creates a clone of the StarlinkCollection ,creating deep
     *        copies of all its members
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
     *        the SpaceStation communicates through
     * @param CommunicationRelay
    */
    void setCommunicationRelaySS(CommunicationRelay*);

    /**
     * @brief Sets the head attribute
     * @param StarlinkSatellite
    */
    void setHead(StarlinkSatellite* head);

    /**
     * @brief Calls the setSatellites(int, int) method on the satelliteManager
     *        to create the StarlinkSatellites and sets num_B and num_S
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

    ///@return int ,returns the num_B member
    int getB();

    ///@return int ,returns the num_S member
    int getS();

    ///@return BaseStation ,returns the BS member
    BaseStation* getBS();

    ///@return SpaceStation ,returns the SS member
    SpaceStation* getSS();

    ///@return CommunicationRelay ,returns the relaySS member
    CommunicationRelay* getCommunicationRelaySS();

    ///@return CommunicationRelay ,returns the relayBS member
    CommunicationRelay* getCommunicationRelayBS();

    ///@return SatelliteManager ,returns the satelliteManager member
    SatelliteManager* getSatelliteManager();

    /**
     * @brief Sends the rocketship back to BaseStation
     * 
     */
    void startLanding(Station* base);
    /**
     * @brief Get the Spacecraft object
     * 
     * @return Spacecraft* 
     */
    virtual Spacecraft* getSpacecraft();
    /**
     * @brief Get the Rocket object
     * 
     * @return FalconRocket* 
     */
    virtual FalconRocket* getRocket();
    /**
     * @brief Get the Cargo object
     * 
     * @return Cargo** 
     */
    virtual Cargo** getCargo();
	/**
     * @brief Attaches a spacecraft to the rocketship
     * 
     * @param s 
     */
	virtual void attachSpacecraft(Spacecraft *s);
    /**
     * @brief Attaches cargo to the Dragon rocketship
     * 
     * @param cvect A vector with all the cargo to be attached to the Dragon rocketship
     */
    virtual void attachCargo(vector<Cargo*> cvect);
private:
    
    /** @brief exact same functionality as the StarlinkCollection bud does not 
    *         set the satelliteManager member ,used exclusively in cloning the StarlinkCollection
    *         the first int parameter is redundant and allosw the overload of the constructor
    */
    StarlinkCollection(int, string name,BaseStation* BS ,SpaceStation* SS);


    ///@brief Set in the StarlinkBay
    ///@brief num_B is the number of StarlinkSatellites that communicate with a BaseStation
    int num_B;
    ///@brief num_S is the number of StarlinkSatellites that communicate with a SpaceStation
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
     * used for communication between StarlinkSatellites and the BaseStation
     */
    CommunicationRelay* relayBS;
    
    /**
     * @brief CommunicationRelay the StarlinkCollection is associated with 
     * used for communication between StarlinkSatellites and the BaseStation
     */
    CommunicationRelay* relaySS;
    /**
     * @brief pointer to StarlinkSatellites linked list created using the SatelliteManager
     * 
     */
    StarlinkSatellite* head;

};

#endif