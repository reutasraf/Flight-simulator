#include "EqualCommand.h"

int EqualCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    //update the var in our map to according to the user change
    map1->at(list1[index])=stoi(list1[index+2]);

    //check if it bind
    if(this->server1->getPath(list1[index+0])!= ""){
        string s = "set ";
        s = s+this->server1->getPath(list1[index]);
        s = s+" "+list1[index]+"\r\n";
        this->dataClient->setData(s);
    }

    return 3;
}
