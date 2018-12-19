//
// Created by reut on 18/12/18.
//

#include <string.h>
#include "ConnectCommand.h"


int ConnectCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {
    string first;
    string second;

    double temp;
    while (){
        if(map1->count(vector1[index][i])){

        }
    }


    dataClient->createSock(stoi(vector1[index][1]),stoi(vector1[index][2]));
    return 3;
}
