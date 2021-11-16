#ifndef MANAGERFACTORY_H
#define MANAGERFACTORY_H

using namespace std;

#include "StarlinkFactory.h"

class ManagerFactory : public StarlinkFactory {
private:
    Satellite* spacecraft;
public:
	ManagerFactory();
	~ManagerFactory();
    Satellite* createRocket();
};

#endif