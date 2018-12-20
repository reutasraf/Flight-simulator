//
// Created by reut on 20/12/18.
//

#include "IfCommand.h"

int IfCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    int size=vector1[index].size();

    int i=1;
    string first="";
    string second="";
    while ((vector1[index][i]!="<")||(vector1[index][i]!=">")||(vector1[index][i]!="=")||(vector1[index][i]!="!")){
        first=first+vector1[index][i]+" ";
        i++;
    }
    string sign = vector1[index][i];
    if (vector1[index][i+1]=="="){
        sign = sign+vector1[index][i+1];
        i++;

    }
    while (vector1[index][i]!="{"){
        second=second+vector1[index][i]+" ";
        i++;
    }
    //double firstParm= this->dijkstra1->operator()(first);
    //double secondParm= this->dijkstra1->operator()(second);

    vector<vector<string>> newVactor=vector1;
    newVactor.erase(newVactor.begin()+0);
    if (returnBoolSign(first,second,sign,map1)){

        this->parser->interpLine(newVactor);
    }

    return 0;

}
bool IfCommand::returnBoolSign(string first, string second, string sign, map<string, double> *map1) {
    double firstParm= this->dijkstra1->operator()(first);
    double secondParm= this->dijkstra1->operator()(second);

    double firstVal = firstParm;
    double secondVal = secondParm;
    //check if the first is var in map
    if(map1->count(first)==1){
        firstVal = map1->at(first);
    } else{
        firstVal=stod(first);
    }
    //check if the second is var in map
    if(map1->count(second)==1){
        secondVal= map1->at(second);
    }else{
        secondVal=stod(second);
    }

    if(sign==">"){
        if(firstVal>secondVal){
            return true;
        } else{
            return false;
        }


    } else if(sign=="<"){
        if(firstVal<secondVal){
            return true;
        } else{
            return false;
        }


    } else if(sign==">="){
        if(firstVal>=secondVal){
            return true;
        } else{
            return false;
        }


    } else if(sign=="<="){
        if(firstVal<=secondVal){
            return true;
        } else{
            return false;
        }


    } else if(sign=="=="){
        if(firstVal==secondVal){
            return true;
        } else{
            return false;
        }
    }
    else if(sign=="!="){
        if(firstVal!=secondVal){
            return true;
        } else{
            return false;
        }

    } else{
        __throw_bad_exception();
    }
}

