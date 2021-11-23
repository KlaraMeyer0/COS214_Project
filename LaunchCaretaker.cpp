#include "LaunchCaretaker.h"

LaunchCaretaker::LaunchCaretaker(){
    FileSize = 0;
    file = new LaunchFile*[0];
    desc = new string[0];
}
LaunchCaretaker::~LaunchCaretaker(){
    for (int i = 0; i < FileSize; i++)
        delete file[i];
    delete file;
}
LaunchFile* LaunchCaretaker::getFile(int i){
    if (i >= FileSize || i < 0) throw std::invalid_argument("Argument outside of range");
    return file[i];
}
void LaunchCaretaker::setFile(LaunchFile* newfile){
    if (newfile == nullptr) throw std::invalid_argument("Argument is null");
    string s = "";
    for (int i = 0; i < newfile->getCount(); i++){
        s = s + newfile->getLaunch()[i]->getName() + newfile->getLaunch()[i]->getType() +"\n";
    }
    FileSize++;
    LaunchFile** f = new LaunchFile*[FileSize];
    string* ss = new string[FileSize];
    for (int i = 0; i < FileSize-1; i++){
        f[i] = file[i];
        ss[i] = desc[i];
    }
    f[FileSize-1] = newfile;
    ss[FileSize-1] = s;
    file = f;
    desc = ss;
}
string LaunchCaretaker::getDesc(int i){
    if (i >= FileSize || i < 0) throw std::invalid_argument("Argument outside of range");
    return desc[i];
}
void LaunchCaretaker::removeFile(int i){
    if (i >= FileSize || i < 0) throw std::invalid_argument("Argument outside of range");
    string* ss = new string[FileSize-1];
    LaunchFile** f = new LaunchFile*[FileSize-1];
    for (int j = 0; j < i; j++){
        f[j] = file[j];
        ss[j] = desc[j];
    }
    for (int j = i; j < FileSize-1; j++){
        f[j] = file[j+1];
        ss[j] = desc[j+1];
    }
    delete file[i];
    FileSize--;
    file = f;
    desc = ss;
}
bool LaunchCaretaker::contains(LaunchFile* f){
    for (int i = 0; i < FileSize; i++){
        for (int j = 0; j < file[i]->getCount(); j++){
            if (f->getLaunch()[i]->getName() == file[i]->getLaunch()[i]->getName()) return true;
        }
    }
    return false;
}
bool LaunchCaretaker::contains(Rocketship** r){
    for (int i = 0; i < FileSize; i++){
        for (int j = 0; j < file[i]->getCount(); j++){
            if (r[j]->getName() == file[i]->getLaunch()[j]->getName()) return true;
        } 
    }
    return false;
}
int LaunchCaretaker::getSize(){
    return FileSize;
}