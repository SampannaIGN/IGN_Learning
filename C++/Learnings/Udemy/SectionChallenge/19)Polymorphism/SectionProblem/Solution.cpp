/*
An Account has a name and a balance. With getbalance,withdraw & deposit functions.
A Savings Account is child of Account and has extra attribute called rate of interest.

Account_Util.cpp does withdraw,display & deposit for vector of accounts

Your challenge is the following:

1. Add a Checking account class to the Account hierarchy
    A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
    Every withdrawal transaction will be assessed this flat fee.

2. Add a Trust account class to the Account hierarchy
    A Trust account has a name, a balance, and an interest rate
    The Trust account deposit works just like a savings account deposit.
    However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.
    
    The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
    You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)
    
Hints: 
    Reuse existing functionality!!
    Think about what the Base class will be for the new classes.
    Add helper functions to Account_Util.h and Account_Util.cpp if you wish to work with your new classes.
    (You don't have to, but it will make your main much easier to use)
    
Have fun!!  You are no longer beginner C++ programmers!

If you want more practice with operator overloading you can overload += and -= for deposit and withdrawal :)
*/ 
#include <iostream>
#include <vector>
#include "Account_Util.h"

using namespace std;

void account_check(){  
    // Accounts
    vector<Account*> accounts;
    Account *t1 = new Account {};
    Account *t2 = new Account {"Larry"};
    Account *t3 = new Account {"Moe", 2000};
    Account *t4 = new Account {"Curly", 5000};


    accounts.push_back(t1);
    accounts.push_back(t2);
    accounts.push_back(t3);
    accounts.push_back(t4);
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);

    delete t1;
    delete t2;
    delete t3;
    delete t4;
}

void savings_account_check(){
    // Savings 
    vector<Account*> sav_accounts;
    Account *t1 = new Savings_Account {};
    Account *t2 = new Savings_Account {"Superman"};
    Account *t3 = new Savings_Account {"Batman", 2000};
    Account *t4 = new Savings_Account {"Wonderwoman", 5000, 5.0};

    sav_accounts.push_back(t1);
    sav_accounts.push_back(t2);
    sav_accounts.push_back(t3);
    sav_accounts.push_back(t4);

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    delete t1;
    delete t2;
    delete t3;
    delete t4;
}

void check_account_check(){
    // Checking
    vector<Account*> check_accounts;
    Account *t1 = new Checking_Account {};
    Account *t2 = new Checking_Account {"Spiderman"};
    Account *t3 = new Checking_Account {"Hero", 2000};
    Account *t4 = new Checking_Account {"Willian", 5000, 5.0};

    check_accounts.push_back(t1);
    check_accounts.push_back(t2);
    check_accounts.push_back(t3);
    check_accounts.push_back(t4);

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    delete t1;
    delete t2;
    delete t3;
    delete t4;
}

void trust_account_check(){
    // Trust    
    vector<Account*> trust_accounts;
    Account *t1 = new Trust_Account{};
    Account *t2 = new Trust_Account {"Justman"} ;
    Account *t3 = new Trust_Account {"Rohit", 2000};
    Account *t4 = new Trust_Account {"RaviKanth", 5000, 5.0};

    trust_accounts.push_back(t1);
    trust_accounts.push_back(t2);
    trust_accounts.push_back(t3);
    trust_accounts.push_back(t4);

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 20);
    withdraw(trust_accounts, 20);
    withdraw(trust_accounts, 20);
    withdraw(trust_accounts, 20);

    delete t1;
    delete t2;
    delete t3;
    delete t4;
}

int main() {
    account_check();
    savings_account_check();
    check_account_check();
    trust_account_check();
    
    return 0;
}

