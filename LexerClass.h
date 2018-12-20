//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_LEXER_H
#define FLIGHT_LEXER_H
#include <string>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

class LexerClass {

    list<string> Lexer();
    list<string> splitToCommand(string line);
    list<list<string>> readFromFile();


    };


#endif //FLIGHT_LEXER_H
