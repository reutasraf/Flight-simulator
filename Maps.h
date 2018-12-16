//
// Created by reut on 16/12/18.
//

#ifndef FLIGHT_MAPS_H
#define FLIGHT_MAPS_H

#include <map>
#include <string>
#include "command.h"
using namespace std;


class Maps {
private:
    map<string,double > symbolTable;
    map<string, Command*> commandMap;
public:
    void setSymbel(string var, double value);
    double getSymbol(string var);
    Command* getCommand(string comamnd);


};


#endif //FLIGHT_MAPS_H
