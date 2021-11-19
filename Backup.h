#ifndef BACKUP_H
#define BACKUP_H

using namespace std;

#include "LaunchInterface.h"
#include "Work.h"

class Backup : public Work{
public:
	Backup();
    ~Backup();
    void execute();
    void undo();
};

#endif