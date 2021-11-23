#include "LaunchInterface.h"

void LaunchInterface::setLaunchFile(LaunchFile* file){
    rocketCount = file->getCount();
    rocketships = file->getLaunch();
}
LaunchFile* LaunchInterface::retrieveLaunchFile(){
    LaunchFile* f = new LaunchFile();
    //make deepcopy of current rocket array
    Rocketship** r = new Rocketship*[rocketCount];
    for (int i = 0; i < rocketCount; i++)
        r[i] = rocketships[i]->clone();
    f->setLaunch(r,rocketCount);
    return f;
}
LaunchInterface::LaunchInterface(Station * s, Station* b){
    rocketships = new Rocketship*[0];
    rocketCount = 0;
    launchCaretaker = new LaunchCaretaker();
    space_station = s;
    base_station = b;
}
LaunchInterface::~LaunchInterface(){
    delete launchCaretaker;
    for (int i = 0; i < rocketCount; i++)
        delete rocketships[i];
    delete rocketships;
}
void LaunchInterface::TestLaunch(){
    //prompt about which rockets to launch
    getDesc();
    bool* b = new bool[rocketCount];
    for (int i = 0; i < rocketCount; i++){
        bool w = true;
        char a;
        do{
            cout<<"Do you want to launch number: "<<i<<"? (y or n)"<<endl;
            cin>>a;
            if (a == 'y'){
                w = false;
                b[i] = true;
            } else if (a == 'n'){
                w = false;
                b[i] = false;
            } else {
                cout<<"Please input either n or y."<<endl;
                cin.clear();
                cin.ignore(15, '\n');
            }
        } while (w);
    }
    //prompt about type of launch
    vector<Launch*> l;//Launch queue
    vector<bool> m;//real or test
    for (int i = 0; i < rocketCount; i++){
        if (b[i]){
            l.push_back(new LaunchReal(rocketships[i],space_station));
            bool w = true;
            char a;
            do{
                cout<<"For launch "<<i<<", do you want to do a real or test launch? (r or t)"<<endl;
                cin>>a;
                if (a == 'r'){
                    m.push_back(true);
                    w = false;
                } else if (a == 't'){
                    m.push_back(false);
                    w = false;
                    //prompt user for tests and assemble decorator
                    cout<<"Setup of test launch for launch "<<i<<endl;
                    bool d = true;
                    do{
                        cout<<"Do you want to have a cargo present test? (y or n)"<<endl;
                        cin>>a;
                        if (a == 'y'){
                            l[i] = new CargoTest(new StopTest(l.at(i)));
                            d = false;
                        } else if (a == 'n'){
                            d = false;
                        } else {
                            cout<<"Please input either n or y."<<endl;
                        }
                        cin.clear();
                        cin.ignore(15, '\n');
                    } while (d);
                    d = true;
                    do{
                        cout<<"Do you want to have an engine fire test? (y or n)"<<endl;
                        cin>>a;
                        if (a == 'y'){
                            l[i] = new EngineFireTest(new StopTest(l.at(i)));
                            d = false;
                        } else if (a == 'n'){
                            d = false;
                        } else {
                            cout<<"Please input either n or y."<<endl;
                        }
                        cin.clear();
                        cin.ignore(15, '\n');
                    } while (d);
                    d = true;
                    do{
                        cout<<"Do you want to have an engine present test? (y or n)"<<endl;
                        cin>>a;
                        if (a == 'y'){
                            d = false;
                            l[i] = new EnginePresentTest(new StopTest(l.at(i)));
                        } else if (a == 'n'){
                            d = false;
                        } else {
                            cout<<"Please input either n or y."<<endl;
                        }
                        cin.clear();
                        cin.ignore(15, '\n');
                    } while (d);
                    cout<<"Setup complete"<<endl;
                } else {
                    cout<<"Please input either r or t."<<endl;
                }
                cin.clear();
                //cin.ignore(15, '\n');
            } while (w);  
        }
    }
    //run tests
    vector<Launch*>::iterator it;
    for (it = l.begin(); it != l.end(); it++){
        (*it)->startLaunch();
    }
    //delete pointers
    for (it = l.begin(); it != l.end(); it++){
        delete (*it);
    }
    delete b;
}
void LaunchInterface::getDesc(){
    cout<<"This is the current setup, please select which rockets to launch:"<<endl;
    for (int i = 0; i < rocketCount; i++){
        string tp;
        switch (rocketships[i]->getType()){
        case 'c':
            tp = "FalconHeavy - Crew";
            break;
        case 'd':
            tp = "FalconHeavy - Cargo";
            break;
        case 's':
            tp = "Falcon9 - Satellites";
            break;
        default:
            break;
        }
        cout<<i<<endl<<rocketships[i]->getName()<<" : "<<tp<<endl;
    }
}
void LaunchInterface::addRocketship(Rocketship* r){//add rocket to current array
    rocketCount++;
    Rocketship** rs = new Rocketship*[rocketCount];
    for (int i = 0; i < rocketCount-1; i++){
        rs[i] = rocketships[i];
        rocketships[i] = nullptr;
        delete rocketships[i];
    }
    rs[rocketCount-1] = r;
    delete rocketships;
    rocketships = rs;
}
void LaunchInterface::storeFile(){//store current file into Caretaker
    LaunchFile* f = retrieveLaunchFile();
    if (!launchCaretaker->contains(f)){
        launchCaretaker->setFile(f);
        rocketships = new Rocketship*[0];
        rocketCount = 0;
    }
}
void LaunchInterface::outputDesc(){
    //output all descriptions
    for (int i = 0; i < rocketCount; i++)
        cout<<i<<endl<<launchCaretaker->getDesc(i)<<endl;
}
void LaunchInterface::restoreFile(){//needs to be tested!!!
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
            cin.clear();
            cin.ignore(15, '\n');
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
        ss >> ws;
        ss.ignore();
        //if (t == NULL)
        if (ss.fail() || !ss.eof())
        {
            cout<<"Please input a number!"<<endl;
            flag = true;
        }
        else if (t >= launchCaretaker->getSize() || t < 0){
            cout<<"The number is out of the range!"<<endl;
            flag = true;
        } else flag = false;
        cin.clear();
        cin.ignore(15, '\n');
    } while (flag);
    //load file
    setLaunchFile(launchCaretaker->getFile(t));
}

int LaunchInterface::getRocketCount()
{
    return rocketCount;
}

Rocketship** LaunchInterface::getAllRockets()
{
    return rocketships;
}

Station* LaunchInterface::getBaseStation()
{
    return base_station;
}