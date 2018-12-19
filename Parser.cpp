//
// Created by reut on 16/12/18.
//

#include "Parser.h"

void Parser::interpLine(vector<vector<string>> vector1) {
    for(int i = 0;i<vector1.size();i++){
        //for the vars equal.
        int jump;
        if(maps->getSymbolMap()->count(vector1[i])==1){
            if(vector1[i]!="="){
                __throw_bad_exception();
            }
            jump =maps->getCommand("equal")->doCommand(vector1,this->maps->getSymbolMap(),i);

        } else{
            jump =maps->getCommand(vector1[i])->doCommand(vector1,this->maps->getSymbolMap(),i);
        }
        i = i+jump;
    }
}
