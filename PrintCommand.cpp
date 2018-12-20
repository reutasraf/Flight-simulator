//
// Created by tehila on 20/12/18.
//

#include "PrintCommand.h"

int PrintCommand::doCommand(vector<vector<string>> vector1,
                            map<string, double> *map1, int index) {

    int size=vector1[index].size();
    if(vector1[index][1].find("\"")!=std::string::npos){
        string toPrint=vector1[index][2].substr(1,(vector1[index][2].size()-2));
        std::cout <<toPrint <<'\n';
    } else{
        string toPrint="";
        for(int i=1;i<size;i++){
            toPrint=toPrint+vector1[index][i];
        }
        double pri=this->dijkstra1->operator()(toPrint);
        std::cout <<pri <<'\n';

    }



    return 2;
}
