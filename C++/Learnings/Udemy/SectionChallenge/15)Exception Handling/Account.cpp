#include "Account.h"

Account::Account():balance{0.0}{}

Account::Account(double balance):balance{balance}{
    if(balance < 0.0)throw IllegalBalanceException();
}

void Account::withdraw(double amount){
    if(balance < amount){
        throw InsufficientFundsException();
    }
    else{
        balance -= amount;
    }
}

double Account::getBalance(){
    return balance;
}

void Account::deposit(double amount){
    if(amount <= 0){
        throw IllegalBalanceException();
    }
    else{
        balance += amount;
    }
}