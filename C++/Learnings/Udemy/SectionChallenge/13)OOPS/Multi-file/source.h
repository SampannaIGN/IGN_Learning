#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>

using namespace std;

class Example{
    private:
    int var;
    string str;

    public:
    Example();
    Example(int,string);

    void function1();
    void setVar(int);
    int getVar();
    void setStr(string);
    string getStr();

    ~Example();
};

#endif