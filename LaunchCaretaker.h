#ifndef LAUNCHCARETAKER_H
#define LAUNCHCARETAKER_H

using namespace std;

#include "LaunchFile.h"

class LaunchCaretaker {
private:
    LaunchFile* file;
public:
	LaunchCaretaker();
	~LaunchCaretaker();
	LaunchFile* getFile();
	void setFile(LaunchFile* file);
};

#endif