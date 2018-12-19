

#include "Maps.h"
#include "openServerCommand.h"
#include "DefineVarCommand.h"
#include "EqualCommand.h"
#include "ConnectCommand.h"
#include "LoopCommand.h"

void Maps::setSymbel(string var, double value){
    this->symbolTable.at(var)=value;
}

double Maps:: getSymbol(string var){
    return this->symbolTable.at(var);
}
Command* Maps:: getCommand(string comamnd){
    return this->commandMap.at(comamnd);
}
map<string,double >* Maps::getSymbolMap() { return &(this->symbolTable);}



void Maps:: initMapCom(){
    Command* openData = new openServerCommand(this->server1,this->dataClient);
    this->commandMap.insert(pair<string, Command*>("openDataServer",openData));
    Command* varCommand = new DefineVarCommand(this->server1,this->dataClient);
    this->commandMap.insert(pair<string, Command*>("var",varCommand));
    Command* equalCommand = new EqualCommand(this->server1,this->dataClient);
    this->commandMap.insert(pair<string, Command*>("equal",equalCommand));
    Command* connectCommand = new ConnectCommand(this->server1,this->dataClient);
    this->commandMap.insert(pair<string, Command*>("connect",equalCommand));
    Command* loopCommand = new LoopCommand(this->server1,this->dataClient,this->commandMap);
    this->commandMap.insert(pair<string, Command*>("while",loopCommand));

}

void Maps::setServer(DataReaderServer* dataReaderServer,DataClient* dataClient1) {
    this->server1 = dataReaderServer;
    this->dataClient = dataClient1;

}


