#include <iostream>
#include "DataReaderServer.h"
#include "Maps.h"
#include "DataClient.h"
#include "Parser.h"
#include "LexerClass.h"

int main() {



    //map<string,double >* symbolTable = new map<string,double >;
    Maps* maps = new Maps;

    //DataReaderServer* drs = new(DataReaderServer(*(maps->getSymbolMap())));
    DataReaderServer* drs = new DataReaderServer(maps->getSymbolMap());
    DataClient* dataClient1 = new DataClient();
    Dijkstra* dijkstra = new Dijkstra(maps->getSymbolMap());
    Parser* parser = new Parser(maps->getSymbolMap(),maps->getComMap());
    maps->setDij(dijkstra);
    maps->setServer(drs,dataClient1);
    maps->setParser(parser);
    maps->initMapCom();



    LexerClass lexerClass;
    vector<vector<string>> afterLex;
    afterLex = lexerClass.readFromFile("tempppppp");
    //drs->createSock(5400, 10);
    //drs->readFromSock();
    parser->interpLine(afterLex);
    int t = 0;
    return 0;
}

