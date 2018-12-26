//
// Created by reut on 20/12/18.
//

#include "IfCommand.h"
/**
 * the if command-take care of if line
 * @param vector1 the vector of the data
 * @param map1 the map of the value of the vars
 * @param index-the index of the current data we need
 * @return
 */
int IfCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    int size=vector1[index].size();

    int i=1;
    string first="";
    string second="";
    int close1 = 0;
    //take care of ( in if
    while ((vector1[index][i]!="<")&&(vector1[index][i]!=">")&&(vector1[index][i]!="=")&&(vector1[index][i]!="!")){
        first=first+vector1[index][i]+" ";

        if(vector1[index][i]=="("){
            close1++;
        }
        if(vector1[index][i]==")"){
            close1--;
        }
        i++;
    }
    if(close1>0){
        first.erase(first.begin(),first.begin()+close1+1);
    }
    close1 = 0;
    string sign = vector1[index][i];
    i++;
    if (vector1[index][i]=="="){
        sign = sign+vector1[index][i];
        i++;

    }
    while (vector1[index][i]!="{"){
        second=second+vector1[index][i]+" ";
        if(vector1[index][i]=="("){
            close1++;
        }
        if(vector1[index][i]==")"){
            close1--;
        }
        i++;
    }
    if(close1<0){
        second.erase(second.begin()+second.size()+close1-2,second.begin()+second.size());
    }
    //double firstParm= this->dijkstra1->operator()(first);
    //double secondParm= this->dijkstra1->operator()(second);
    vector<vector<string>> newVactor=vector1;
    newVactor.erase(newVactor.begin()+0);
    for(int o = 0;o<newVactor[newVactor.size()-1].size();o++){
        if(newVactor[newVactor.size()-1][o]=="}"){
            newVactor[newVactor.size()-1].erase(newVactor[newVactor.size()-1].begin()+o);
            break;
        }
    }
    if(newVactor[newVactor.size()-1].size()==0){
        newVactor.erase(newVactor.begin()+newVactor.size());
    }
    if (returnBoolSign(first,second,sign,map1)){

        this->parser->interpLine(newVactor);
    }

    return 0;

    /*
    int size=vector1[index].size();

    int i=1;
    string first="";
    string second="";
    while ((vector1[index][i]!="<")&&(vector1[index][i]!=">")&&(vector1[index][i]!="=")&&(vector1[index][i]!="!")){
        first=first+vector1[index][i]+" ";
        i++;
    }
    string sign = vector1[index][i];
    if (vector1[index][i+1]=="="){
        sign = sign+vector1[index][i+1];
        i++;

    }
    while (vector1[index][i]!="{"){
        second=second+vector1[index][i]+" ";
        i++;
    }
    //double firstParm= this->dijkstra1->operator()(first);
    //double secondParm= this->dijkstra1->operator()(second);

    vector<vector<string>> newVactor=vector1;
    newVactor.erase(newVactor.begin()+0);
    if (returnBoolSign(first,second,sign,map1)){

        this->parser->interpLine(newVactor);
    }

    return 0;
*/


}
/**
 *
 * @param first the first value or var
 * @param second  the second value or var
 * @param sign  the sign of the condition
 * @param map1  map of vars
 * @return true if the condition is true.else return false
 */
bool IfCommand::returnBoolSign(string first, string second, string sign, map<string, double> *map1) {
    double firstParm= this->dijkstra1->toVl(first);
    double secondParm= this->dijkstra1->toVl(second);

    double firstVal = firstParm;
    double secondVal = secondParm;

    if(sign==">"){
        if(firstVal>secondVal){
            return true;
        } else{
            return false;
        }


    } else if(sign=="<"){
        if(firstVal<secondVal){
            return true;
        } else{
            return false;
        }


    } else if(sign==">="){
        if(firstVal>=secondVal){
            return true;
        } else{
            return false;
        }


    } else if(sign=="<="){
        if(firstVal<=secondVal){
            return true;
        } else{
            return false;
        }


    } else if(sign=="=="){
        if(firstVal==secondVal){
            return true;
        } else{
            return false;
        }
    }
    else if(sign=="!="){
        if(firstVal!=secondVal){
            return true;
        } else{
            return false;
        }

    } else{
        __throw_bad_exception();
    }
}

