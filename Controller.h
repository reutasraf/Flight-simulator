//
// Created by reut on 26/12/18.
//

#ifndef FLIGHT_CONTROLLER_H
#define FLIGHT_CONTROLLER_H

#include <string>
#include <iostream>
#include "DataReaderServer.h"
#include "Maps.h"
#include "DataClient.h"
#include "Parser.h"
#include "LexerClass.h"
using namespace std;


class Controller {
public:
    void playProgrem(string file);

};


#endif //FLIGHT_CONTROLLER_H
