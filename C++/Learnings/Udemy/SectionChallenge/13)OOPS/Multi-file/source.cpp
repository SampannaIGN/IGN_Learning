#include <iostream>
#include "source.h"

using namespace std;

Example::Example(int var, string str){
    this->var = var;
    this->str = str;
}

Example::Example(){
    str = "";
    var = 0;
}

void Example::function1(){
    cout<<"function1"<<endl;
}

void Example::setVar(int var){
    this->var = var;
}

int Example::getVar(){
    return var;
}

void Example::setStr(string str){
    this->str = str;
}

string Example::getStr(){
    return str;
}

Example::~Example(){
    cout<<"Destructor Executed"<<endl;
}