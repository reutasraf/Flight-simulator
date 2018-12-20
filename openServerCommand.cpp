#include "openServerCommand.h"void* OpenThreadFunc(void* args){
    ///read
    struct dataToSoc* params=(struct dataToSoc*) args;
    params->server2->createSock(params->port,params->timeRead);
    while (true)    {
        auto x = params->server2->readFromSock();
        if (x == "exit") break;
    }





    return nullptr;
}
void* openServerCommand:: OpenThread(void* pVoid) {
    //struct dataToSoc* params=new dataToSoc;
    //params->port=this->port;
    //params->timeRead=this->time;
    struct dataToSoc* params=(struct dataToSoc*) pVoid;
    pthread_t trid;
    pthread_create(&trid, nullptr,OpenThreadFunc,params);
    return 0;
}



#include <pthread.h>
struct dataToSoc{
    int port;
    int timeRead;
    DataReaderServer* server2;

};

int openServerCommand::doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index) {

    //if we dont have correct number of elements
   //convert to num from exp.
    //this->port = stoi(list1[1+index]);
    this->port = stoi(vector1[index][1]);
    //this->time = stoi(list1[2+index]);
    this->time = stoi(vector1[index][2]);


    //open the thread
    struct dataToSoc* params=new dataToSoc;
    params->port=this->port;
    params->timeRead=this->time;
    params->server2=this->server1;
    this->OpenThread(params);
    delete(params);
    return 3;

}

void* OpenThreadFunc(void* args){
    ///read
    struct dataToSoc* params=(struct dataToSoc*) args;
    params->server2->createSock(params->port,params->timeRead);
    while (true)    {
        auto x = params->server2->readFromSock();
        if (x == "exit") break;
    }





    return nullptr;
}
void* openServerCommand:: OpenThread(void* pVoid) {
    //struct dataToSoc* params=new dataToSoc;
    //params->port=this->port;
    //params->timeRead=this->time;
    struct dataToSoc* params=(struct dataToSoc*) pVoid;
    pthread_t trid;
    pthread_create(&trid, nullptr,OpenThreadFunc,params);
    return 0;
}


