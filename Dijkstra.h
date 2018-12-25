//
// Created by reut on 20/12/18.
//

#ifndef FLIGHT_DIJKSTRA_H
#define FLIGHT_DIJKSTRA_H


#include "BinaryExpression.h"
#include "Plus.h"
#include "Num.h"

#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "Expression.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Dijkstra {
    map<string,double>* var_to_val;
    int precedence(char op);

public:
    Dijkstra(map<string, double>* var_to_val);


private:
    Expression* applyOp(double a, double b, char op);
    vector<string> splitLine(const string &str, char sign);
    vector<BinaryExpression*> deleteVector;

    double calculate(string tokens);
    double evaluate(string tokens);

public:
    double virtual operator()(char* str);
    double virtual toVl(string str);
    void addToDelete(BinaryExpression* exp);
    ~Dijkstra(){
        vector<BinaryExpression*>::iterator it = this->deleteVector.begin();
        for(it;it!=this->deleteVector.end();++it){
            delete (*it)->getRight();
            delete (*it)->getLeft();
            delete (*it);
        }
    }

};


#endif //FLIGHT_DIJKSTRA_H
