#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee)
    : Account {name, balance}, fee{fee} {
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount+fee);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance<<"]";
    return os;
}

