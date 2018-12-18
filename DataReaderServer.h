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
#include <vector>

using namespace std;

class DataReaderServer {
private:
    struct sockaddr_in m_socket;
    int sock_fd, client_sock_fd;
    double time;
    map<string, string>* mapPath;
    map<string,double > pathRead;
    map<string,double >* realMap;


public:
    DataReaderServer(map<string,double >* realMap){
        this->realMap = realMap;
        buildMap();
    }
    int createSock(int num1, int num2);
    string readFromSock();
    void addPath(string var,string path);
    void accept();
    string getPath(string var);
    void buildMap();
    vector<double > split(string buff);
    void setMapPath(vector<double> vector1);
    void updateMap();
    //struct sockaddr_in getSock();

};


#endif //FLIGHT_DATAREADERSERVER_H
