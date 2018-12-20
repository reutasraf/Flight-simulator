//
// Created by tehila on 20/12/18.
//

#ifndef FLIGHT_PRINTCOMMAND_H
#define FLIGHT_PRINTCOMMAND_H


#include "Command.h"

class PrintCommand : public Command{
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);

};


#endif //FLIGHT_PRINTCOMMAND_H
