/**
 * @file PointOfCommunication.h
 * @class PointOfCommunication
 * @author Klara Meyer ,Luca Loubser
 * 
 * @brief
 * Design Pattern: Mediator, Prototype
 * Participant: Colleague, Prototype
 */


#ifndef SATELLITE_H
#define SATELLITE_H

using namespace std;

class PointOfCommunication {
    public:
        /**
         * @brief 
         * Construct a new PointOfCommunication instanse and sets the name member variable
         * to a random number between 1-1000 ,sets the status member to true indicating the 
         * PointOfCommunication instanse is functional
         */
        PointOfCommunication();    

        /**
         * @brief Destructor of the PointOfCommunication instanse
         */
	    virtual ~PointOfCommunication();

        /**
         * @brief Construct a new PointOfCommunication instanse
         * @return bool reflecting the status of the PointOfCommunication instance, true if functional ,false otherwise
         */
        bool getStatus();

        /**
         * @brief Set the status of the PointOfCommunication instance
         * @param status bool that represents if the PointOfCommunication is functional
         */
        void setStatus(bool status);

        /**
         * @brief Get the name of the PointOfCommunication instanse
         * @return int representing the name of the PointOfCommunication instance
         */
        int getName();

        /**
         * @brief Set the Name of the PointOfCommunication instanse
         * @param name int that will replace the name of the PointOfCommunication instance
         */
        void setName(int name);
    private:

        ///@brief int randomly generated in PointOfCommunication() identifier 
        int name;       

        ///@brief true ,if functional false otherwise
        bool status;    
};

#endif