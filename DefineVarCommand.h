

#ifndef FLIGHT_DEFINEVARCOMMAND_H
#define FLIGHT_DEFINEVARCOMMAND_H

#include "Command.h"

class DefineVarCommand: public Command{
public:
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);
    DefineVarCommand(DataReaderServer* server5,DataClient* dataClient1):Command(server5,dataClient1){}


};

#endif //FLIGHT_DEFINEVARCOMMAND_H
