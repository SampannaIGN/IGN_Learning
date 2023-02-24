/*
center conversion

Ask user to enter cent value

1 dollar = 100cents
1 quarter = 25cents
1 dime = 10cents
1 nickel = 5cents
1 penny = 1cent


Ex: Approach
535

input = 536  => =5  (536%100)  remaining = 536-(5*100)
input = 36   => =1  (36%25) remaining = 36-(1*25)
input = 11   => =1  (11%10) remaining = 11-(1*10)
input = 1    => =0  (1%5) remaining = input
input = 1    => =1
*/
#include <iostream>

using namespace std;

unsigned int get_count(unsigned int cent, unsigned int cent_per_type){
    if(cent == 0)return 0;

    return cent/cent_per_type;
}

unsigned int get_remainder(unsigned int cent, unsigned int cent_per_type, unsigned int type_value){
    if(type_value == 0)return cent;

    return cent-(type_value*cent_per_type);
}

void cent_conversion(){
    const int cent_per_dollar = 100;
    const int cent_per_quarter = 25;
    const int cent_per_dime = 10;
    const int cent_per_nickel = 5;
    const int cent_per_penny = 1;

    unsigned int cent;
    
    cout<<"Enter an amount in cents = ";
    cin>>cent;

    unsigned int amount_count;

    amount_count = get_count(cent,cent_per_dollar);
    cent = get_remainder(cent,cent_per_dollar,amount_count);
    cout<<"dollars = "<<amount_count<<endl;

    amount_count = get_count(cent,cent_per_quarter);
    cent = get_remainder(cent,cent_per_quarter,amount_count);
    cout<<"quarters = "<<amount_count<<endl;

    amount_count = get_count(cent,cent_per_dime);
    cent = get_remainder(cent,cent_per_dime,amount_count);
    cout<<"dimes = "<<amount_count<<endl;

    amount_count = get_count(cent,cent_per_nickel);
    cent = get_remainder(cent,cent_per_nickel,amount_count);
    cout<<"nickel = "<<amount_count<<endl;

    amount_count = get_count(cent,cent_per_penny);
    cent = get_remainder(cent,cent_per_penny,amount_count);
    cout<<"pinney = "<<amount_count<<endl;
}

int main(){
    cent_conversion();
    return 0;
}