#include "LaunchInterface.h"

void LaunchInterface::setLaunchFile(LaunchFile* file){//sets the given Launchfile as the current rocket setup
    rocketCount = file->getCount();
    rocketships = file->getLaunch();
}
LaunchFile* LaunchInterface::retrieveLaunchFile(){//create backup Launchfile for current selection of rockets
    LaunchFile* f = new LaunchFile();
    //make deepcopy of current rocket array
    Rocketship** r = new Rocketship*[rocketCount];
    for (int i = 0; i < rocketCount; i++)
        r[i] = rocketships[i]->clone();
    f->setLaunch(r,rocketCount);
    return f;
}
LaunchInterface::LaunchInterface(){
    launchCaretaker = new LaunchCaretaker();
}
LaunchInterface::~LaunchInterface(){
    delete launchCaretaker;
    for (int i = 0; i < rocketCount; i++)
        delete rocketships[i];
    delete rocketships;
}
void LaunchInterface::TestLaunch(){
    //prompt about which rockets to launch
    //prompt about type of launch

    //Launch* l = new LaunchReal();

    //prompt user for tests and assemble decorator
    //Run tests
}
void LaunchInterface::addRocketship(Rocketship* r){//add rocket to current array
    rocketCount++;
    Rocketship** rs = new Rocketship*[rocketCount];
    rs[rocketCount-1] = r;
}
void LaunchInterface::storeFile(){//store current file into Caretaker
    LaunchFile* f = retrieveLaunchFile();
    if (!launchCaretaker->contains(f))
        launchCaretaker->setFile(f);
}
void LaunchInterface::outputDesc(){
    //output all descriptions
    for (int i = 0; i < rocketCount; i++)
        cout<<i<<endl<<launchCaretaker->getDesc(i)<<endl;
}
void LaunchInterface::restoreFile(){//needs to be tested!!!
    //check if current setup is backed up
    if (!launchCaretaker->contains(rocketships)) {
        bool flag = false;
        do{
            cout<<"Do you want to make a backup of the current launch arrangement before overwriting? (input y/n)"<<endl;
            string s;
            cin>>s;
            if (s == "y") {
                storeFile();
                flag = false;
                }
            if (s == "n") flag = false;
            else {
                cout<<"Please input y or n only."<<endl;
                flag = true;
            }
        } while (flag);
    }
    outputDesc();
    //allow a number to be inputted determining which file to load
    bool flag = false;
    int t;
    do {
        cout<<"Input the number of which file to load, d to output the descriptions again, or q to cancel the overwrite"<<endl;
        string n;
        cin>>n;
        if (n == "q"){
            cout<<"Cancelling..."<<endl;
            return;
        }
        if (n == "d"){
            outputDesc();
            flag = true;
            continue;
        }
        stringstream ss;
        ss<<n;
        ss>>t;
        ss.clear();
        if (t == NULL){
            cout<<"Please input a number!"<<endl;
            flag = true;
            }
        else if (t >= launchCaretaker->getSize() || t < 0){
            cout<<"The number is out of the range!"<<endl;
            flag = true;
        } else flag = false;
    } while (flag);
    //load file
    setLaunchFile(launchCaretaker->getFile(t));
}