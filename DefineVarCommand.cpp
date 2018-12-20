

#include "DefineVarCommand.h"
#include <string>
using namespace std;
int DefineVarCommand::doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index){

                        // string temp = list1[index+3];
    string temp = vector1[index][3];
    //if var is bind
    if(temp.compare("bind")==0){
                        //map1->insert(pair<string,double >(list1[index+1],0));
        map1->insert(pair<string,double >(vector1[index][1],0));

        string nameVar = vector1[index][1];
        this->server1->addPath(nameVar,vector1[index][4]);
        this->server1->updateMap();
        return 5;

        //if var isn't bind
    }else{
        string var = vector1[index][1];
                                    //temp = list1[index+3];
        string valueExp="";
        for (int i=3;i<vector1[index].size();i++){
            valueExp=valueExp+vector1[index][i]+" ";
        }

        //TODO sent value to expression and save in val
        double val;

        map1->insert(pair<string, double>(var,val));
/*
        bool dig = false;
        for(int i =0; i<temp.size();i++){
            if((temp[i]>=48)&&(temp[i]<=57)){
                dig = true;
            } else{
                dig= false;
                break;
            }
        }
        if(!dig){
            if(map1->count(temp)==1){
                map1->insert(pair<string, double>(var,map1->at(temp)));
            } else{
                __throw_bad_exception();
            }
            //if it is a number
        } else{
            map1->insert(pair<string, double>(var,stoi(temp)));
        }
*/

        return 4;

    }

}

