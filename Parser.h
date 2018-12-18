//
// Created by reut on 16/12/18.
//

#ifndef FLIGHT_PARSER_H
#define FLIGHT_PARSER_H

#include "Maps.h"
#include <map>


class Parser {
private:
    Maps* maps;
public:

    void interpLine(vector<string>);


};


#endif //FLIGHT_PARSER_H
