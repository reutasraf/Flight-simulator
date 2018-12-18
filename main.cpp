#include <iostream>
#include "DataReaderServer.h"


int main() {

    DataReaderServer drs;
    drs.createSock(5400, 10);
    drs.readFromSock();
    return 0;
}

