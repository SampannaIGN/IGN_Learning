/*
1)Derive IllegalBalanceException from exception class and Implement what()
2)Create account class whose constructor should throw IllegalBalanceException
if the balance provided is -ve
3)llly Derive InsufficientFundsException from exception class and implement what()
Note: this exception should be thrown if withdraw results is a negative balance.(throw 
from Account withdraw method)

*/

#include <iostream>
#include "Account.h"

using namespace std;

int main(){
    for(int i = 0; i < 10; i++){
        try{
            if(i%2 == 0){
                throw 10;
            }
            else{
                cout<<"i="<<i<<endl;
            }
        }
        catch(...){
            cerr<<"Exception"<<endl;
        }
    }
}
/*int main(){
    Account my_account;
    try{
        my_account.deposit(999.99);
        cout<<"Balance = "<<my_account.getBalance()<<endl;
        //my_account.deposit(0);//=>Illegal Balance Exception
        my_account.withdraw(10);
        cout<<"Balance = "<<my_account.getBalance()<<endl;
        //my_account.withdraw(10000);//=>Insufficient Funds Exception
        //Account my_account2(-2);//=>Illegal Balance Exception
        
    }
    catch(IllegalBalanceException &ibe){
        cerr<<ibe.what()<<endl;
    }
    catch(InsufficientFundsException &ife){
        cerr<<ife.what()<<endl;
    }

    cout<<"Done"<<endl;

    return 0;
}*/