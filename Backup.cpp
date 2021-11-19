#include "Backup.h"

Backup::Backup(LaunchInterface* i){
    interface = i;
}
void Backup::execute(){
    interface->storeFile();
}
void Backup::undo(){

}