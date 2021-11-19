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
    return file[i];
}
void LaunchCaretaker::setFile(LaunchFile* newfile){
    string s;
    cout<<"Please input a description:"<<endl;//add description? would help with organising and selecting a new launch setup, replace with automatic?
    cin>>s;
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
    return desc[i];
}
void LaunchCaretaker::removeFile(int i){
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