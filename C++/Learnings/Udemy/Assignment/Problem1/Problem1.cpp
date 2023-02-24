/*
Problem in brief=>
    Given arr = {3,2,6,1,4,7,8,5,9,10}

return array such that each element is element/max{arr}
    i.e. result = {0.3,0.2....}
*/

#include <iostream>
#include "my_array_util.cpp"
#include "my_array.cpp"

using namespace std;

void solution(){
    int arr_size;
    cout<<"Enter the size of array = ";
    cin>>arr_size;
    my_array <int,double>obj(arr_size);
    cout<<obj<<endl;
}

int main(){
    solution();
    return 0;
}
