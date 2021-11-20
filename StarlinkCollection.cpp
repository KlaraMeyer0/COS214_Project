#ifndef STARLINKCOLLECTION_CPP
#define STARLINKCOLLECTION_CPP
#include "StarlinkCollection.h"
using namespace std;


	
    StarlinkCollection:: StarlinkCollection(string name): Rocketship(name){

    }
    
	~StarlinkCollection();
    void Launch();


    SatelliteIterator* begin();
    SatelliteIterator* end();
    
    Rocketship* clone();
    StarlinkSatellite* getFirstSat();

///members
    FalconRocket* rocket;
    vector<StarlinkSatellite*>* satellites;
    int numSatellites;
    SatelliteManager* satelliteCreator;
    int num_G;
    int num_O;


#endif