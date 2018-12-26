#include <iostream>
#include "DataReaderServer.h"
#include "Maps.h"
#include "DataClient.h"
#include "Parser.h"
#include "LexerClass.h"
#include "Controller.h"
int main(int argc, char* argv[])  {

    Controller controller;
    controller.playProgrem(argv[1]);

    return 0;

}

