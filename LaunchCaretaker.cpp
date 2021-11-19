#include "LaunchCaretaker.h"

LaunchCaretaker::LaunchCaretaker(){}
LaunchCaretaker::~LaunchCaretaker(){
    delete file;
}
LaunchFile* LaunchCaretaker::getFile(){
    return file;
}
void LaunchCaretaker::setFile(LaunchFile* file){
    cout<<"Please input a description:"<<endl;//add description? would help with organising and selecting a new launch setup
    cin>>desc;
    this->file = file;
}
string LaunchCaretaker::getDesc(){
    return desc;
}