//
// Created by reut on 18/12/18.
//

#ifndef FLIGHT_WHILECOMMAND_H
#define FLIGHT_WHILECOMMAND_H

#include "Command.h"

class LoopCommand: public Command {

private:
    vector<Command> commands;
public:
    virtual int doCommand(vector<string> list1,map<string, double>* map1,int index);
    bool returnBoolSign(string first,string second,string sign, map<string, double> *map1);
};


#endif //FLIGHT_WHILECOMMAND_H
