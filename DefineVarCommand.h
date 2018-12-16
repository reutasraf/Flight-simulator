//
// Created by reut on 16/12/18.
//

#ifndef FLIGHT_DEFINEVARCOMMAND_H
#define FLIGHT_DEFINEVARCOMMAND_H

#include "command.h"

class DefineVarCommand: public Command{
public:
    virtual int doCommand(list<string> list1,map<string, double> map1);

};

#endif //FLIGHT_DEFINEVARCOMMAND_H
