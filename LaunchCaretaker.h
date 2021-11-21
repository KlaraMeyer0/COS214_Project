#ifndef LAUNCHCARETAKER_H
#define LAUNCHCARETAKER_H

using namespace std;

#include "LaunchFile.h"

class LaunchCaretaker {//Memento caretaker
public:
	LaunchCaretaker();
	~LaunchCaretaker();
	LaunchFile* getFile(int i);
	void setFile(LaunchFile* newfile);
	string getDesc(int i);
	void removeFile(int i);
	bool contains(LaunchFile*);
	bool contains(Rocketship**);
	int getSize();
private:
    LaunchFile** file;
	string* desc;
	int FileSize;
};

#endif