#ifndef SPACECRAFT_H
#define SPACECRAFT_H

using namespace std;

class Spacecraft {
public:
	Spacecraft(int capacity);
	~Spacecraft();
private:
	int cargoCapacity;
};

#endif