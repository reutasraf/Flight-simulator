#include <iostream>
#include "DataReaderServer.h"
#include "Maps.h"


int main() {


    //map<string,double >* symbolTable = new map<string,double >;
    Maps* maps = new Maps;
    DataReaderServer drs(*(maps->getSymbolMap()));
    drs.createSock(5400, 10);
    drs.readFromSock();
    return 0;
}

