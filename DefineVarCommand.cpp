

#include "DefineVarCommand.h"
#include <string>
using namespace std;

/**
 * the var command-take care of the vars in the program accordingg to the user scripts(if it bind or not etc..).
 * @param vector1 the vector of the data
 * @param map1 the map of the value of the vars
 * @param index-the index of the current data we need
 * @return
 */
int DefineVarCommand::doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index){

    string temp = vector1[index][3];

    //if var is bind
    if(temp.compare("bind")==0){
        //add to map
        pthread_mutex_lock(this->mut);
        map1->insert(pair<string,double >(vector1[index][1],0));
        pthread_mutex_unlock(this->mut);

        //if the 4th elemt is in the map
        if(map1->count(vector1[index][4])==1){
            string path25 = this->server1->getPath(vector1[index][4]);
            this->server1->addPath(vector1[index][1],path25);
        } else{
            string nameVar = vector1[index][1];
            string path = vector1[index][4];
            path = path.substr(1,path.size()-2);
            this->server1->addPath(nameVar,path);
        }
        this->server1->updateMap();
        return 5;

    //if var isn't bind
    }else{
        string var = vector1[index][1];
        string valueExp="";
        //take care of the value-calculate it and insert to the map
        for (int i=3;i<vector1[index].size();i++){
            valueExp=valueExp+vector1[index][i]+" ";
        }
        double val=this->dijkstra1->toVl(valueExp);
        pthread_mutex_lock(this->mut);
        map1->insert(pair<string, double>(var,val));
        pthread_mutex_unlock(this->mut);
        return 4;

    }


}

