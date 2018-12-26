//
// Created by reut on 18/12/18.
//

#include <string.h>
#include "ConnectCommand.h"

/**
 * the connection command-creat the socket that connect to the flight
 * with the data we get from the user.
 * @param vector1 the vector of the data
 * @param map1 the map of the value of the vars
 * @param index-the index of the current data we need
 * @return
 */
int ConnectCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    string second;

    //take care of the port number
    int size=vector1[index].size();

    for(int i=2;i<size;i++){
        second=second+vector1[index][i]+" ";
    }
    double portVal=this->dijkstra1->toVl(second);

    //creat the socket
    dataClient->createSock(vector1[index][1],portVal);
    return 3;
}
