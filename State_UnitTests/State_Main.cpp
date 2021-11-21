#include <iostream>
#include "Falcon9.h"
#include "FalconHeavy.h"
#include "FalconRocket.h"

int State_Main () {
	Falcon9 F9 = Falcon9();
	cout << endl << "Testing falcon 9" << endl;
	F9.turnOn();
	F9.turnOn();
	F9.turnOff();
	FalconRocket* F92 = F9.clone();
	cout << endl << "Testing falcon 9 clone" << endl;
	F92->turnOn();
	F92->turnOff();
	F92->turnOn();
	F92->turnOff();
	cout << "" << endl;
	FalconHeavy FH = FalconHeavy();
	cout << endl << "Testing falcon heavy" << endl;
	FH.turnOn();
	FH.turnOn();
	FH.turnOff();
	FalconRocket* FH2 = FH.clone();
	cout << endl << "Testing falcon heavy clone" << endl;
	FH2->turnOn();
	FH2->turnOff();
	FH2->turnOn();
	FH2->turnOff();   

	return 0;
}