

#ifndef FLIGHT_DEFINEVARCOMMAND_H
#define FLIGHT_DEFINEVARCOMMAND_H

#include "Command.h"

class DefineVarCommand: public Command{
public:
    virtual int doCommand(vector<string> list1,map<string, double>* map1,int index);
    DefineVarCommand(DataReaderServer* server5):Command(server5){}


};

#endif //FLIGHT_DEFINEVARCOMMAND_H
