
#ifndef FLIGHT_CONNECTCOMMAND_H
#define FLIGHT_CONNECTCOMMAND_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <map>
#include "Command.h"
using namespace std;

class ConnectCommand: public Command {
private:
    struct sockaddr_in m_socket;
    int sock_fd, client_sock_fd;

public:
    ConnectCommand(DataReaderServer* server2):Command(server2){}
    int createSock(int num1, int num2);
    void set(string path);
    virtual int doCommand(vector<string> list1,map<string, double>* map1,int index);


};


#endif //FLIGHT_CONNECTCOMMAND_H
