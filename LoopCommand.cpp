//
// Created by reut on 18/12/18.
//

#include "LoopCommand.h"

int LoopCommand::doCommand(vector<string> list1, map<string, double> *map1, int index) {
    string firstParam = (list1[index+1]);
    string secondParam = (list1[index+3]);
    string sign = list1[2+index];





    return 0;
}

bool LoopCommand::returnBoolSign(string first, string second, string sign, map<string, double> *map1) {
    double firstVal = 0;
    if(map1->count(first)==1){
        firstVal = map1->at(first);
    } else{

    }
    if(sign==">"){

        // TODO return stoi()





    } else if(sign=="<"){

    } else if(sign==">="){

    } else if(sign=="=>"){

    } else if(sign=="=="){}
    else if(sign=="!="){

    } else{
        __throw_bad_exception();
    }
}
