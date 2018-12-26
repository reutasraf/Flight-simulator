//
// Created by reut on 24/12/18.
//

#include "ExitCommand.h"

/**
 * the exit command-free all the memory tha allocated
 * @param vector1 the vector of the data
 * @param map1 the map of the value of the vars
 * @param index-the index of the current data we need
 * @return
 */
int ExitCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    //stop the loop
    this->server->stopLoop();

    //free memory
    delete this->dij;
    delete this->dataClient1;
    close(this->server->getSockId());
    delete this->server;
    pthread_mutex_destroy(mut);
    delete this->mut;

}
