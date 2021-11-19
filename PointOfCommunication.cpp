#ifndef SATELLITE_CPP
#define SATELLITE_CPP
#include "PointOfCommunication.h"
using namespace std;

PointOfCommunication::PointOfCommunication(int name){
    this->name =name;
    status =false;
}

PointOfCommunication::~PointOfCommunication(){
}

#endif