#ifndef HUMAN_H
#define HUMAN_H

using namespace std;

#include "Cargo.h"

class Human : public Cargo {
public:
	Human(string);
	~Human();
    Cargo* clone();
};

#endif