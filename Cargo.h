#ifndef CARGO_H
#define CARGO_H

using namespace std;

#include <string>

class Cargo {
private:
    string name;
    bool human;
public:
	Cargo(string);
	~Cargo();
    string getName();
    bool isHuman();
};

#endif