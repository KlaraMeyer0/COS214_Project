#ifndef HUMANFACTORY_H
#define HUMANFACTORY_H

using namespace std;

class HumanFactory : public CargoFactory {
public:
	HumanFactory();
	~HumanFactory();
    Cargo* createRocket();
};

#endif