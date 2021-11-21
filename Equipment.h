#ifndef EQUIPMENT_H
#define EQUIPMENT_H

using namespace std;

#include "Cargo.h"

class Equipment : public Cargo
{
public:
	Equipment(string);
	~Equipment();
    Cargo* clone();
};

#endif