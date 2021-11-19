#ifndef SATELLITE_H
#define SATELLITE_H

using namespace std;

class PointOfCommunication {
    public:
	    PointOfCommunication(int);
	    ~PointOfCommunication();
    private:
        int name;
        bool status;
};

#endif