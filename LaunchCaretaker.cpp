#include "LaunchCaretaker.h"

LaunchCaretaker::LaunchCaretaker(){
    //add description? would help with organising and selecting a new launch setup
}
LaunchCaretaker::~LaunchCaretaker(){
    delete file;
}
LaunchFile* LaunchCaretaker::getFile(){
    return file;
}
void LaunchCaretaker::setFile(LaunchFile* file){
    this->file = file;
}