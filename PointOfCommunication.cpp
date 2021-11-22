#ifndef SATELLITE_CPP
#define SATELLITE_CPP
#include "PointOfCommunication.h"
#include <ctime>
#include <cstdlib>
using namespace std;

PointOfCommunication::PointOfCommunication(){
    static int i =0;
    if(i==0){
        srand(time(0));
        ++i;
    }
    //random number between 1-1000 serves as identifier of PointOfCommunication 
    name = rand() % (1000) +1;
    status =true;
}

PointOfCommunication::~PointOfCommunication(){
}

bool PointOfCommunication:: getStatus(){
    return status;
}

void PointOfCommunication:: setStatus(bool status){
    this->status = status;
}

int PointOfCommunication:: getName(){
    return name;
}

void PointOfCommunication::setName(int name){
    this->name =name;
}

#endif