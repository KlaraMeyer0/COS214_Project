#ifndef EQUITMENTFACTORY_H
#define EQUITMENTFACTORY_H

using namespace std;

class EquitmentFactory : public CargoFactory {
public:
	EquitmentFactory();
	~EquitmentFactory();
    Cargo* createRocket();
};

#endif