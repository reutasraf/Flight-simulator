#include <iostream>
#include "DataReaderServer.h"
#include "Maps.h"
#include "DataClient.h"

int main() {


    //map<string,double >* symbolTable = new map<string,double >;
    Maps* maps = new Maps;
    //DataReaderServer* drs = new(DataReaderServer(*(maps->getSymbolMap())));
    DataReaderServer* drs = new DataReaderServer(maps->getSymbolMap());
    DataClient* dataClient1 = new DataClient();
    maps->setServer(drs,dataClient1);
    drs->createSock(5400, 10);
    drs->readFromSock();
    return 0;
}

