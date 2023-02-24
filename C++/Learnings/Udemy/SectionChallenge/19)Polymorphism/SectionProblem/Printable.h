#ifndef _PRINTABLE_H
#define _PRINTABLE_H
#include <iostream>

using namespace std;

class Printable{
    friend ostream& operator<<(ostream &sout,const Printable &pritable); 
    virtual ostream& print(ostream &sout)const=0;
};

#endif