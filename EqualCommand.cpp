#include "EqualCommand.h"

int EqualCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    //update the var in our map to according to the user change
                                // map1->at(list1[index])=stoi(list1[index+2]);
     string valueExpr="";
     //save the value we need to update
     for (int i=2;i<vector1[index].size();i++){
         valueExpr=valueExpr+vector1[index][i]+" ";

     }
     //TODO sent value to expression and save in val
    double val=this->dijkstra1->operator()(valueExpr);


                            //map1->at(vector1[index][0])=stod(vector1[index][2]);
    map1->at(vector1[index][0])=val;

    //check if it bind
                                //if(this->server1->getPath(list1[index+0])!= ""){
    if(this->server1->getPath(vector1[index][0])!= ""){
            string s = "set ";
        s = s+this->server1->getPath(vector1[index][0]);
                                            //s = s+" "+vector1[index][0]+"\r\n";
        s = s+" "+to_string(val)+"\r\n";
        this->dataClient->setData(s);
    }

    return 3;
}
