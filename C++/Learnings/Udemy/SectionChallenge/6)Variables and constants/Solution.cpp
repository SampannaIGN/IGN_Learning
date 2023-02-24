/*
Charges => $25 for small rooms & $35 for large rooms
Sales tax rate of 6%
Estimate for 30 days

o/p format
Ask for no. of small & large rooms
print price per small room & price per large room
print cost
print tax

print total extimate
print "Estimate is valid for 30 days"

*/


#include <iostream>

using namespace std;

inline double get_cost(int small_room_count, double small_room_price, int large_room_count, double large_room_price){
    return (small_room_count*small_room_price)+(large_room_count*large_room_price);
}

inline double get_tax(double cost, double tax_rate){
    return cost*(tax_rate);
}

void estimateTax(){
    const double small_room_price = 25;
    const double large_room_price = 35;
    const double tax_rate = 6.0/100;

    int small_room_count,large_room_count;

    cout<<"Enter number of small rooms = ";
    cin>>small_room_count;

    cout<<"Enter number of large rooms = ";
    cin>>large_room_count;
    
    double cost = get_cost(small_room_count,small_room_price,large_room_count,large_room_price);
    cout<<"Cost : $"<<cost<<endl;

    double tax = get_tax(cost,tax_rate);
    cout<<"Tax : $"<<tax<<endl;

    double total_estimate = cost+tax;
    cout<<"Total Estimate = "<<total_estimate<<endl;
    cout<<"This estimate is valid for 30 days"<<endl;

}

int main()
{
    estimateTax();
    return 0;
}
