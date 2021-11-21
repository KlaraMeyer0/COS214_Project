#ifndef SATELLITE_H
#define SATELLITE_H

using namespace std;

class PointOfCommunication {
    public:
        PointOfCommunication();    
	    virtual ~PointOfCommunication();
        bool getStatus();
        void setStatus(bool);
        int getName();
        void setName(int);
    private:
        int name;       //randomly generated identifier 
        bool status;    //true ,if functional false otherwise
};

#endif