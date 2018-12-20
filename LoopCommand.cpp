//
// Created by reut on 18/12/18.
//

#include "LoopCommand.h"
#include <string>
using namespace std;

int LoopCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    string firstParam = (vector1[0][1]);

    string secondParam = (vector1[0][3]);
    string sign = vector1[0][2];
    vector<vector<string>> newVactor=vector1;
    newVactor.erase(newVactor.begin()+0);
    while (returnBoolSign(firstParam,secondParam,sign,map1)){
        this->parser->interpLine(newVactor);
    }

    return 0;
}

bool LoopCommand::returnBoolSign(string first, string second, string sign, map<string, double> *map1) {
    double firstVal = 0;
    double secondVal = 0;
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


    } else if(sign=="=="){}
    else if(sign=="!="){

    } else{
        __throw_bad_exception();
    }
}

void LoopCommand::MakeCommandsVectors(vector<string> vec)  {
    for(vector<string>::iterator it=vec.begin();it!=vec.end();++it){

    }
}
