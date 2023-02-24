#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

//      Trust Account is a type of Savings account
// Withdraw - 
//      can withdraw only 20% of amount & withdrawal limit is 3
// Deposit:
//      When amount greater than or equal to 5000 is deposited 
//      500 extra will be credited

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    
    int count;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_
