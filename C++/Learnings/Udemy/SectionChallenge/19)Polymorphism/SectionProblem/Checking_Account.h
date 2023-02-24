#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

// Checking Account is a type of Account
// adds an extra fee
// Withdraw - 
// adds an extra fee while withdrawing
// Deposit - same as a regular Account

class Checking_Account: public Account {
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_fee = 0.0;
protected:
    double fee;
public:
    Checking_Account(std::string name = def_name, double balance =def_balance, double fee = def_fee);    
    virtual bool withdraw(double amount);
    virtual ostream& print(ostream &sout)const override;
    // Inherits the Account::deposit method
};

#endif // _CHECKING_ACCOUNT_H_
