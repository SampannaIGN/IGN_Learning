#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std;

class Account{
    private:
    double balance;
    
    public:
    Account();
    Account(double balance);

    void withdraw(double amount);
    double getBalance();
    void deposit(double amount);
};

#endif