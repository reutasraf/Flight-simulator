

#ifndef FLIGHT_OPENSERVERCOMMAND_H
#define FLIGHT_OPENSERVERCOMMAND_H

#include "Command.h"

class openServerCommand: public Command{
private:
    int port;
    int time;
public:
   //int doCommand(list<string>);
   virtual int doCommand(vector<string> list1,map<string, double>* map1,int index);

    //void* OpenThreadFunc(void* args);
    void* OpenThread(void* pVoid);
    openServerCommand(DataReaderServer* server5):Command(server5){}

};
#endif //FLIGHT_OPENSERVERCOMMAND_H
