//
// Created by reut on 13/12/18.
//

#include "DataReaderServer.h"
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>

int DataReaderServer:: createSock(int port, int time){
    int portno;
    //struct sockaddr_in serv_addr, cli_addr;


    /* First call to m_socket() function */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        perror("ERROR opening m_socket");
        exit(1);
    }

    /* Initialize m_socket structure */
    bzero((char *) &this->m_socket, sizeof(this->m_socket));
    portno = port;

    this->m_socket.sin_family = AF_INET;
    this->m_socket.sin_addr.s_addr = INADDR_ANY;
    this->m_socket.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sock_fd, (struct sockaddr *) &this->m_socket, sizeof(this->m_socket)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sock_fd,1);
    this->time=time;

    accept();
}


void DataReaderServer::accept()
{
    std::cout << "Waiting for connection..." << endl;
    sockaddr_in client_sock;
    int clilen;
    client_sock_fd = ::accept(sock_fd, (struct sockaddr*) &client_sock, (socklen_t *)&clilen);
    if (client_sock_fd < 0) {
        // TODO error
    }
    std::cout << "hi" << std::endl;

}

string DataReaderServer::readFromSock(){
//todo while
    char buffer[1000];
    ssize_t bytes_read;
    bytes_read = read(this->client_sock_fd, buffer, 999);
    if (bytes_read < 0) {
        // TODO error
    }   else if (bytes_read == 0)   {
        // TODO connection closed
        int y = 0;
    } else  {
        buffer[bytes_read] = NULL;
        cout << buffer;
    }

    return "";

}

void DataReaderServer::addPath(string var,string path){
    this->mapPath->insert(pair<string,string>(var,path));
}

string DataReaderServer::getPath(string var) {
    if(this->mapPath->count(var)==1){
        return this->mapPath->at(var);
    }
    return "";
}



//struct sockaddr_in getSock(){}