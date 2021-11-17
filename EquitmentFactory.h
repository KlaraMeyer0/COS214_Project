#ifndef EQUITMENTFACTORY_H
#define EQUITMENTFACTORY_H

using namespace std;

#include "CargoFactory.h"

class EquitmentFactory : public CargoFactory {
public:
	EquitmentFactory();
	~EquitmentFactory();
    Cargo* createRocket();
};

#endif