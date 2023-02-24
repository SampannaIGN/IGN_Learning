#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
:Savings_Account(name,balance,int_rate),count{0}{
}

bool Trust_Account::deposit(double amount){
    if(amount >= 5000){
        return Savings_Account::deposit(amount+500);
    }
    else{
        return Savings_Account::deposit(amount);
    }
}

bool Trust_Account::withdraw(double amount){
    cout<<"**********"<<endl;
    if(count >= 3){
        std::cout<<"Withdrawal limit exceeded!!!"<<std::endl;
        return false;
    }
    else{
        if(amount >= balance*0.2){
            std::cout<<"Only 20% of amount can be withdrawn!!!"<<std::endl;
            return false;
        }
        else{
            count++;
            return Savings_Account::withdraw(amount);
        }   
    }
}

ostream& Trust_Account::print(ostream &sout)const{
    sout << "[Trust_Account: " << name << ": " << balance << ", " << int_rate << "%]";
    return sout;
}
