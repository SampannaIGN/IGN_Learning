// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

#include "Printable.h"

class Account: public Printable{
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    double get_balance() const;
    virtual ostream& print(ostream &sout)const override;//Printable interface method overriding
};
#endif