#ifndef CARGO_H
#define CARGO_H

using namespace std;

#include <string>

class Cargo {
private:
    string name;
    bool human;
public:
	Cargo(string, bool h);
	~Cargo();
    string getName();
    bool isHuman();
    virtual Cargo* clone() = 0;
};

#endif