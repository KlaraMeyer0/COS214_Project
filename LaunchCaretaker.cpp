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
    if (i >= FileSize || i < 0) throw "Argument outside of range.\n";
    return file[i];
}
void LaunchCaretaker::setFile(LaunchFile* newfile){
    if (newfile == nullptr) throw "Argument is null.\n";
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
    f[FileSize] = newfile;
    ss[FileSize] = s;
    file = f;
    desc = ss;
}
string LaunchCaretaker::getDesc(int i){
    if (i >= FileSize || i < 0) throw "Argument outside of range.\n";
    return desc[i];
}
void LaunchCaretaker::removeFile(int i){
    if (i >= FileSize || i < 0) throw "Argument outside of range.\n";
    FileSize--;
    string* ss = new string[FileSize];
    LaunchFile** f = new LaunchFile*[FileSize];
    for (int j = 0; j < i; j++){
        f[j] = file[j];
        ss[j] = desc[j];
    }
    for (int j = i; j < FileSize+1; j++){
        f[j] = file[j+1];
        ss[j] = desc[j];
    }
    delete file[i];
    file = f;
    desc = ss;
}
bool LaunchCaretaker::contains(LaunchFile* f){
    for (int i = 0; i < FileSize; i++){
        if (f == file[i]) return true;
    }
    return false;
}
bool LaunchCaretaker::contains(Rocketship** r){
    for (int i = 0; i < FileSize; i++){
        if (r == file[i]->getLaunch()) return true;
    }
    return false;
}
int LaunchCaretaker::getSize(){
    return FileSize;
}