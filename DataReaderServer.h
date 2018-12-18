//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_DATAREADERSERVER_H
#define FLIGHT_DATAREADERSERVER_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <map>
using namespace std;

class DataReaderServer {
private:
    struct sockaddr_in m_socket;
    int sock_fd, client_sock_fd;
    double time;
    map<string, string>* mapPath;
public:
    DataReaderServer() = default;
    int createSock(int num1, int num2);
    string readFromSock();
    void addPath(string var,string path);
    void accept();
    string getPath(string var);
    //struct sockaddr_in getSock();

};


#endif //FLIGHT_DATAREADERSERVER_H
