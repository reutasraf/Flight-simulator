//
// Created by reut on 18/12/18.
//

#ifndef FLIGHT_WHILECOMMAND_H
#define FLIGHT_WHILECOMMAND_H

#include "Command.h"

class LoopCommand: public Command {

private:
    vector<Command> commands;
    vector<int> indexForCommand;
    map<string,Command*> mapComm;
public:
    LoopCommand(DataReaderServer* server5,DataClient* dataClient1,map<string,Command*> mapComm1
    ):Command(server5,dataClient1){
        this->mapComm = mapComm1;
    }
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);
    bool returnBoolSign(string first,string second,string sign, map<string, double> *map1);
    void MakeCommandsVectors(vector<string>);
};

#endif //FLIGHT_WHILECOMMAND_H
