//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_NUM_H
#define FLIGHT_NUM_H


#include "Expression.h"

class Num: Expression {

private:
    double num;
public:
    virtual double calculate();
    Num(double num);

};


#endif //FLIGHT_NUM_H
