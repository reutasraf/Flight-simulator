//
// Created by reut on 13/12/18.
//
#include "lexer1.h"
#include <fstream>
#include <string.h>
#include <map>
#include <list>

using namespace std;
vector<string> lexer1::lexer(string buffer) {

    vector<string> info;
    size_t pos = 0;
    string delimiter = " ";
    while ((pos = buffer.find(delimiter)) != string::npos) {
        info.push_back(buffer.substr(0, pos));
        buffer.erase(0, pos + delimiter.length());
    }
    info.push_back(buffer.substr(0, pos));
    return info;
}
/**
 * read from file to make the list of string for the parser
 * @param fileName
 * @return
 */
vector<string> lexer1:: readFromFile(string fileName){
    /*list<string> info;
    ifstream myFile;
    string buffer;
    myFile.open(fileName, ifstream::in | ifstream::app);
    if (!myFile) {
        throw "Failed Opening File";
    }
    while (getline(myFile, buffer)) {
        list<string> line;
        if (buffer == "") {
            continue;
        }
        line = lexer(buffer);
        line.splice(line.begin(),info);
        info = line;
        line.clear();
    }
    return info;*/
}




