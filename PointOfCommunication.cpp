#ifndef SATELLITE_CPP
#define SATELLITE_CPP
#include "PointOfCommunication.h"
#include <ctime>
#include <cstdlib>
using namespace std;

PointOfCommunication::PointOfCommunication(){
    srand(time(0));
    //random number between 1-1000 serves as identifier of PointOfCommunication 
    name = rand() % (1000) +1;
    status =false;
}

PointOfCommunication::~PointOfCommunication(){
}

bool PointOfCommunication:: getStatus(){
    return status;
}

void PointOfCommunication:: setStauts(bool status){
    this->status = status;
}

int PointOfCommunication:: getName(){
    return name;
}

void PointOfCommunication::setName(int name){
    this->name =name;
}

#endif