#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee)
    : Account {name, balance}, fee{fee} {
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount+fee);
}

ostream& Checking_Account::print(ostream &sout)const{
    sout << "[Checking_Account: " << name << ": " << balance<<"]";
    return sout;
}

