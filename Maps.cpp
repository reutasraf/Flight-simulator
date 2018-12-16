//
// Created by reut on 16/12/18.
//

#include "Maps.h"

void Maps::setSymbel(string var, double value){
    this->symbolTable.at(var)=value;
}

double Maps:: getSymbol(string var){
    return this->symbolTable.at(var);
}
Command* Maps:: getCommand(string comamnd){
    return this->commandMap.at(comamnd);
}