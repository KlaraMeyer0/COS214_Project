#include <iostream>
#include "Falcon9.h"
#include "FalconHeavy.h"
#include "FalconRocket.h"

int main () {
	Falcon9 F9 = Falcon9();
	cout << endl << "Testing falcon 9" << endl;
	F9.turnOn();
	FalconRocket* F92 = F9.clone();
	cout << endl << "Testing falcon 9 clone" << endl;
	F92->turnOn();
	cout << "" << endl;
	FalconHeavy FH = FalconHeavy();
	cout << endl << "Testing falcon heavy" << endl;
	FH.turnOn();
	FalconRocket* FH2 = FH.clone();
	cout << endl << "Testing falcon heavy clone" << endl;
	FH2->turnOn();
	return 0;
}