#ifndef INSUFFICIENT_FUNDS_EXCEPTION_H
#define INSUFFICIENT_FUNDS_EXCEPTION_H

#include <iostream>
using namespace std;

class InsufficientFundsException:public exception{
    public:
    InsufficientFundsException()=default;
    virtual const char * what() const noexcept;
};

#endif