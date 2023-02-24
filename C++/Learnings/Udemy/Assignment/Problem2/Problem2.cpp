/*
Problem in brief =>
Create 2 arrays of size given by user and generate
random values and store them in these 2 arrays
Finally calculate the eucledian distance and print them
*/
#include <iostream>
#include "my_array.cpp"

using namespace std;

void solution(){
    srand(time(0));
    int row;
    int col;
    cout<<"Enter number of rows = ";
    cin>>row;
    cout<<"Enter number of cols = ";
    cin>>col;
    my_array <double>obj(row,col);
    cout<<"Array1 is ";
    obj.display_arr1();
    cout<<"Array2 is ";
    obj.display_arr2();
    cout<<"Eucledian distance is ";
    obj.display_ED();
}

int main(){
    solution();
    return 0;
}