#ifndef BACKUP_H
#define BACKUP_H

using namespace std;

#include "LaunchInterface.h"
#include "Work.h"

class Backup : public Work{
public:
	Backup(LaunchInterface*);
    ~Backup();
    void execute();
    void undo();
    void setInterface(LaunchInterface*);
private:
    LaunchInterface* interface;
};

#endif