/*
Create a class such that when it is instantiated memory of N will be allocated

write 2 functions
1) fill_array() => which fills the array with values 0 to N
2) get_array() => which returns the array pointer

Finally display the values in the array
*/
#include <iostream>
#include "my_array.cpp"

using namespace std;

void solution(){
    int size;
    cout<<"Enter the size of array to be created = ";
    cin>>size;

    /*Initializing my_array object*/
    my_array <int>obj1(size);
    cout<<"Printing using operator<< overloading = ";
    cout<<obj1;

    /*Checking get_array() method*/
    const int *ptr = obj1.get_array();
    cout<<"Printing after getting the pointer = ";
    for(int i = 0; i < size; i++)cout<<ptr[i]<<" ";
    cout<<endl;
}

int main(){
    solution();
    return 0;
}