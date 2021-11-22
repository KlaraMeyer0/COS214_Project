#ifndef BASESTATION_H
#define BASESTATION_H

#include <vector>

using namespace std;

#include "Station.h"
#include "EquipmentHandler.h"

class BaseStation : public Station
{
public:
    BaseStation();
    virtual ~BaseStation();
    void receiveCargo(Cargo *c);
    void receiveCommunication(string s);
    void printEquipment();
    void printHumans();
    pair<Cargo*, int>* loadEquipment(int idx, int num);
    Cargo* loadHumans(int idx);
    
    BaseStation* clone();

    private:
        CargoHandler* handler;
};

#endif
