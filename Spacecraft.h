#ifndef SPACECRAFT_H
#define SPACECRAFT_H

using namespace std;

class Spacecraft {
public:
	Spacecraft(int capacity);
	~Spacecraft();
	int getCapacity();
	virtual Spacecraft* clone () = 0;
private:
	int cargoCapacity;
};

#endif