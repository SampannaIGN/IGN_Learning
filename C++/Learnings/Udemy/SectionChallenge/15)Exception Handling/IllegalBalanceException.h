#ifndef ILLEGAL_BALANCE_EXCEPTION_H
#define ILLEGAL_BALANCE_EXCEPTION_H

#include <iostream>
using namespace std;

class IllegalBalanceException:public exception{
    public:
    IllegalBalanceException() noexcept = default;
    virtual const char * what() const noexcept;
};

#endif