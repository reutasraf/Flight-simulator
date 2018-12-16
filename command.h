//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_COMMAND_H
#define FLIGHT_COMMAND_H
#include <string>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

class Command
{
public:
    virtual int doCommand(list<string> list1,map<string, double> map1)=0;
};


#endif //FLIGHT_COMMAND_H
