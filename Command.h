//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_COMMAND_H
#define FLIGHT_COMMAND_H
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include "DataReaderServer.h"
using namespace std;

class Command
{
protected:
    DataReaderServer* server1;

public:
    Command(DataReaderServer* server2){
        this->server1 = server2;
    }
    virtual int doCommand(vector<string> list1,map<string, double>* map1,int index)=0;
};


#endif //FLIGHT_COMMAND_H
