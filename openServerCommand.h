//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_OPENSERVERCOMMAND_H
#define FLIGHT_OPENSERVERCOMMAND_H

#include "command.h"

class openServerCommand: public Command{
private:
    int port;
    int time;
public:
   int doCommand(list<string>);
};
#endif //FLIGHT_OPENSERVERCOMMAND_H
