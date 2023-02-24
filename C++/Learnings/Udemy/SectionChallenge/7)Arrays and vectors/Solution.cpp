/*
Create vector1 & vector2 of int type

add 10,20 to vector1
Display vector1 elements along with size

add 100,200 to vector2
Display vector2 elements along with size

create an empty 2D vector
add vector1 & vector2 to it

Display elements of vector2D

change vector1 0th element to 1000
Display elements of vector2D again
Display elements of vector1 again

*/

#include <iostream>
#include <vector>

using namespace std;

void display_vector(vector <int>&vector){
    for(int value:vector)cout<<value<<" ";
    cout<<endl;
}

void display_vector2D(vector <vector<int>>&vector2D){
    for(vector <int>vector1D:vector2D){
        for(int value:vector1D){
            cout<<value<<" ";
        }
        cout<<endl;
    }
}

void vector_operation(){
    vector <int>vector1;
    vector <int>vector2;
    vector <vector<int>>vector2D;
    
    vector1.push_back(10);
    vector1.push_back(20);

    cout<<"vector1 elements are ";
    display_vector(vector1);
    cout<<"size = "<<vector1.size()<<endl;

    vector2.push_back(100);
    vector2.push_back(200);
    
    cout<<"vector2 elements are ";
    display_vector(vector2);
    cout<<"size = "<<vector2.size()<<endl;

    vector2D.push_back(vector1);
    vector2D.push_back(vector2);

    cout<<"vector2D elements before change are "<<endl;
    display_vector2D(vector2D);
    vector1.at(0) = 1000;
    cout<<"vector2D elements after change are "<<endl;
    display_vector2D(vector2D);
    cout<<"vector1 elements after change are ";
    display_vector(vector1);
    
}

int main()
{
    vector_operation();
    return 0;
}
