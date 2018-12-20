#include "openServerCommand.h"
#include <pthread.h>
struct dataToSoc{
    double port;
    double timeRead;
    DataReaderServer* server2;

};

int openServerCommand::doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index) {

                        //this->port = stoi(list1[1+index]);
                        //this->time = stoi(list1[2+index]);
    int indexSeparate = 0;
    //if there are just 2 parameters
    if (vector1[index].size() == 3) {
        this->port = stod(vector1[index][1]);
        this->time = stod(vector1[index][2]);
        //its complicate expression
    } else {
        for (int i = 1; i < vector1[index].size(); ++i) {
            if (vector1[index][i] == ",") {
                indexSeparate = i;
                break;
            }
            // num " " num
            if (((vector1[index][i][0] >= 48) &&
                 (vector1[index][i][0] <= 57)) &&
                ((vector1[index][i + 2][0] >= 48) &&
                 (vector1[index][i + 2][0] <= 57)) &&
                (vector1[index][i + 1] == " ")) {
                indexSeparate = i;
                break;
            }

        }
        //if the it separate by comma / two num separate by " " -sent to expression
        string portString = "";
        string timeString = "";
        if (indexSeparate != 1) {
            for (int i = 1; i < indexSeparate; ++i) {
                portString = portString + vector1[index][i] + " ";
            }
            for (int i = indexSeparate + 1; i < vector1[index].size(); ++i) {
                timeString = timeString + vector1[index][i] + " ";
            }
            double portVal=this->dijkstra1->operator()(portString);
            double timeVal=this->dijkstra1->operator()(timeString);

            this->port = portVal;
            this->time = timeVal;

            return 1;

        }
        //if it end with -num
        int size = vector1[index].size();
        if ((vector1[index][size - 2] == "-") &&
            (isdigit(vector1[index][size - 1][0]))) {
            for (int i = 1; i < size - 3; ++i) {
                portString = portString + vector1[index][i] + " ";
            }
            double portVal=this->dijkstra1->operator()(portString);
            this->port = portVal;
            this->time = stod(vector1[index][size - 1]);

            return 1;
        }

        //if it complex -need to find where to separate
        for (int i = 1; i < size - 2; ++i) {
            if ((isdigit(vector1[index][i][0])) &&
                (vector1[index][i + 1] == " ") &&
                (isdigit(vector1[index][i + 2][0]))) {
                indexSeparate = i;
            }

        }
        double portVal=this->dijkstra1->operator()(portString);
        this->time = stod(vector1[index][size - 1]);

        return 1;
    }
        //open the thread
        struct dataToSoc *params = new dataToSoc;
        params->port = this->port;
        params->timeRead = this->time;
        params->server2 = this->server1;
        this->OpenThread(params);
        delete (params);
        return 3;



}

void* OpenThreadFunc(void* args){
    ///read
    struct dataToSoc* params=(struct dataToSoc*) args;
    //params->server2->createSock(params->port,params->timeRead);
    while (true)    {
        auto x = params->server2->readFromSock();
        if (x == "exit") break;
    }

    return nullptr;
}
void* openServerCommand:: OpenThread(void* pVoid) {
    //struct dataToSoc* params=new dataToSoc;
    //params->port=this->port;
    //params->timeRead=this->time;
    struct dataToSoc* params=(struct dataToSoc*) pVoid;
    pthread_t trid;
    params->server2->createSock(params->port,params->timeRead);
    pthread_create(&trid, nullptr,OpenThreadFunc,params);
    return 0;
}


