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

#include <string.h>

#include <sys/socket.h>


class DataReaderServer {
private:
    struct sockaddr_in socket;
public:
    int createSock(int num1, int num2);
    //struct sockaddr_in getSock();

};


#endif //FLIGHT_DATAREADERSERVER_H
