#ifndef ROCKETSHIPBAY
#define ROCKETSHIPBAY

using namespace std;

class RocketshipBay {
public:
	RocketshipBay();
    ~RocketshipBay();
    virtual void buildRocket() = 0;
    virtual void buildBody() = 0;
    virtual void buildCargo() = 0;
};

#endif