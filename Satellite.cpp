#ifndef SATELLITE_CPP
#define SATELLITE_CPP
#include "Satellite.h"
using namespace std;

Satellite::Satellite(int name){
    this->name =name;
    status =false;
}

Satellite::~Satellite(){
}

#endif