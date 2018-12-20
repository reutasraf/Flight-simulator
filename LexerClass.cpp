//
// Created by reut on 13/12/18.
//
#include "LexerClass.h"
#include <fstream>
#include <string.h>
#include <map>
#include <list>
#include <regex>

using namespace std;

list<string> LexerClass::Lexer() {
    //reading from file or console
    string i ="openDataServer 5400 10 connect 127.0.0.1 5402";
    return splitToCommand(i);
}

list<string> LexerClass:: splitToCommand(string line){
/*    size_t found;
    size_t begining;
    string myVal;
    list<string> resultArray;
    while (line.size() > 0) {
        found = line.find_first_of(" ");
        myVal = line.substr(0, found);
        begining = found + 1;
        line = line.substr(begining, line.size());
        resultArray.push_back(line);
    }
    return resultArray;*/

    //string line = "I 66 + 9 am \"looking\" for 3 + 5 fdgdfgfggdfgdgdfgdfdf GeeksForGeek \n";
    list<string> listOfterLex;
    string enterTolist = "";
    regex number("[0-9,.]*");
    regex var_name("[a-zA-Z_][a-zA-Z_0-9]*");
    regex stringEx("\"[a-zA-Z_0-9]*\"");
    regex whiteSpaces("[\t,\n, ]");
    regex operators("[+,-,/,*]");
    smatch m;

    while(line.size()>0) {
        if (line[0] == '"') {
            regex_search(line, m, stringEx);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            listOfterLex.push_back(enterTolist);
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        } else if (line[0] == '\t' || line[0] == '\n' || line[0] == ' ') {
            regex_search(line, m, whiteSpaces);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        } else if (line[0] > 48 && line[0] < 58) {
            regex_search(line, m, number);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            listOfterLex.push_back(enterTolist);
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        } else if ((line[0] >= 65 && line[0] <= 90) || (line[0] >= 97 && line[0] <= 122)) {
            regex_search(line, m, var_name);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            listOfterLex.push_back(enterTolist);
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        } else {
            regex_search(line, m, operators);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            listOfterLex.push_back(enterTolist);
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        }

    }
}

list<list<string>>  LexerClass:: readFromFile(){
    string command;
    string line;
    string buffer;
    size_t found;
    size_t begining = 0;
    list<list<string>> list;
    ifstream myfile ("Input.txt");
    if(myfile.good()) {
        while (getline(myfile, line)) {
            list.push_back(splitToCommand(line));
        }
    }
    return list;
}


