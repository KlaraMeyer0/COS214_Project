#ifndef EQUITMENT_H
#define EQUITMENT_H

using namespace std;

#include "Cargo.h"

class Equitment : public Cargo {
public:
	Equitment(string);
	~Equitment();
};

#endif