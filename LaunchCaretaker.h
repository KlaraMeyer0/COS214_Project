#ifndef LAUNCHCARETAKER_H
#define LAUNCHCARETAKER_H

using namespace std;

#include "LaunchFile.h"

class LaunchCaretaker {//Memento caretaker
private:
    LaunchFile* file;
	string desc;
public:
	LaunchCaretaker();
	~LaunchCaretaker();
	LaunchFile* getFile();
	void setFile(LaunchFile* file);
	string getDesc();
};

#endif