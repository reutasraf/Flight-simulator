//
// Created by reut on 18/12/18.
//

#include "LoopCommand.h"
#include <string>
using namespace std;

int LoopCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    //initilize the command vectore
    MakeCommandsVectors();

    string firstParam = (list1[index+1]);

    string secondParam = (list1[index+3]);
    string sign = list1[2+index];

    //check if the condition is correct
    while (returnBoolSign(firstParam,secondParam,sign,map1)){
        for(vector<Command>::iterator it=this->commands.begin();it!=this->commands.end();++it){
            (*it).doCommand(list1,map1,index);
        }
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
