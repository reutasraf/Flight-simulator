//
// Created by reut on 18/12/18.
//

#ifndef FLIGHT_EXPRESSIONCOMMAND_H
#define FLIGHT_EXPRESSIONCOMMAND_H

#include "Expression.h"
#include "Command.h"

class ExpressionCommand: public Expression {
private:
    Command* c;
public:
     double calculate();
    ExpressionCommand(Command* c );

};


#endif //FLIGHT_EXPRESSIONCOMMAND_H
