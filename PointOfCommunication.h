#ifndef SATELLITE_H
#define SATELLITE_H

using namespace std;

class PointOfCommunication {
    public:
        PointOfCommunication();    
	    ~PointOfCommunication();
        bool getStatus();
        void setStauts(bool);
        int getName();
        void setName(int);
    private:
        int name;
        bool status;
};

#endif