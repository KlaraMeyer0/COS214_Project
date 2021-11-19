#ifndef SATELLITE_H
#define SATELLITE_H

using namespace std;

class Satellite {
    public:
	    Satellite(int);
	    ~Satellite();
    private:
        int name;
        bool status;
};

#endif