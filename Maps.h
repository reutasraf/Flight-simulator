//
// Created by reut on 16/12/18.
//

#ifndef FLIGHT_MAPS_H
#define FLIGHT_MAPS_H

#include <map>
#include <string>
#include "Command.h"
#include "DataClient.h"
using namespace std;


class Maps {
private:
    map<string,double > symbolTable;
    map<string, Command*> commandMap;
    DataReaderServer* server1 ;
    DataClient* dataClient;
public:
    /*Maps(){
        this->server1 = new DataReaderServer((this->getSymbolMap()));
    }*/
    void setSymbel(string var, double value);
    double getSymbol(string var);
    Command* getCommand(string comamnd);
    map<string,double >* getSymbolMap();
    void initMapCom();
    void setServer(DataReaderServer* dataReaderServer,DataClient* dataClient1 );


};


#endif //FLIGHT_MAPS_H
