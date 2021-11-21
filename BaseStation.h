#ifndef BASESTATION_H
#define BASESTATION_H

#include <vector>

using namespace std;

#include "Station.h"

class BaseStation : public Station
{
public:
    BaseStation();
    virtual ~BaseStation();
    void receiveCargo(Cargo *c, int amount);
    void receiveCommunication(string s);
    void printEquipment();
    void printHumans();
    pair<Cargo*, int>* loadEquipment(int idx, int num);
    Cargo* loadHumans(int idx);
    
    BaseStation* clone();

private:
    vector<pair<Cargo *, int>> equipment;
    vector<Cargo *> humans;
};

#endif
