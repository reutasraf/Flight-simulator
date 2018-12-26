//
// Created by reut on 26/12/18.
//

#include "Controller.h"
/**
 * run the program.
 * @param file the name of the file we get ffom user
 */
void Controller::playProgrem(string file) {

    pthread_mutex_t *mut = new pthread_mutex_t();
    pthread_mutex_init(mut, nullptr);
    Maps* maps = new Maps(mut);
    DataReaderServer* drs = new DataReaderServer(maps->getSymbolMap(),mut);
    DataClient* dataClient1 = new DataClient();
    Dijkstra* dijkstra = new Dijkstra(maps->getSymbolMap());
    Parser* parser = new Parser(maps->getSymbolMap(),maps->getComMap());
    maps->setDij(dijkstra);
    maps->setServer(drs,dataClient1);
    maps->setParser(parser);
    maps->initMapCom();
    LexerClass lexerClass;
    vector<vector<string>> afterLex;

    //read from the file
    //string fileName="tempppppp";
    string fileName=file;


    //pthread_mutex_destroy(&mut);

    afterLex = lexerClass.readFromFile(fileName);
    int ans = parser->interpLine(afterLex);

    if(ans == 0){
        drs->stopLoop();
        pthread_mutex_destroy(mut);
        delete mut;
        delete dijkstra;
        delete parser;
        delete dataClient1;
        close(drs->getSockId());
        delete drs;
    }

    delete parser;
    delete maps;

}
