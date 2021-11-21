#ifndef BACKUP_H
#define BACKUP_H

using namespace std;

#include "Work.h"

class Backup : public Work{
public:
	Backup(LaunchInterface*);
    virtual ~Backup();
    void execute();
    void undo();
private:
    LaunchInterface* interface;
};

#endif