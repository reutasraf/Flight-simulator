

#ifndef FLIGHT_EQUALCOMMAND_H
#define FLIGHT_EQUALCOMMAND_H

#include "Command.h"

class EqualCommand :public Command{

public:
    virtual int doCommand(vector<string> list1, map<string, double> *map1, int index);
    EqualCommand(DataReaderServer* server5):Command(server5){}

};


#endif //FLIGHT_EQUALCOMMAND_H
