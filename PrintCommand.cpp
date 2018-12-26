//
// Created by tehila on 20/12/18.
//

#include "PrintCommand.h"
#include "iostream"

/**
 * the print command-print the value the user want to the screen
 * @param vector1 the vector of the data
 * @param map1 the map of the value of the vars
 * @param index-the index of the current data we need
 * @return
 */
int PrintCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    int size=vector1[index].size();
    int find =0;
    if((find = vector1[index][1].find("\""))!=std::string::npos){
        string pri = vector1[index][1];
        pri.erase(pri.begin()+find);
        find = pri.find("\"");
        pri.erase(pri.begin()+find,pri.begin()+ pri.size());
        //string toPrint=vector1[index][1].substr(1,(vector1[index][2].size()-2));
        //std::cout << pri <<'\n';
    } else{
        string toPrint="";
        for(int i=1;i<size;i++){
            toPrint=toPrint+vector1[index][i]+" ";
        }
        double pri=this->dijkstra1->toVl(toPrint);
        //cout << pri <<'\n';

    }



    return 2;
}
