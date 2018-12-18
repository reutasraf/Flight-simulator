

#include "DefineVarCommand.h"
#include <string>
using namespace std;
int DefineVarCommand::doCommand(vector<string> list1,map<string, double>* map1,int index){
    string temp = list1[index+3];
    if(temp.compare("bind")==0){
        //list1.pop_front();
        map1->insert(pair<string,double >(list1[index+1],0));
        string nameVar = list1[index+1];
        //list1.pop_front();
        this->server1->addPath(nameVar,list1[index+4]);
        //list1.pop_front();
        this->server1->readFromSock();
        return 5;
    }else{
        temp = list1[index+1];
        string var = temp;
        //list1.pop_front();
        temp = list1[index+3];
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
                ////what to do?? אין את זה במפה וזה משתנה מה עושייייםםםם
            }
            //if it is a number
        } else{
            map1->insert(pair<string, double>(var,stoi(temp)));
        }
        return 4;
        //list1.pop_front();

    }

}

