//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_MUL_H
#define FLIGHT_MUL_H


#include "BinaryExpression.h"

class Mul: public BinaryExpression {
public:
    virtual double calculate();
    Mul(Expression *left,Expression *right);

};


#endif //FLIGHT_MUL_H
