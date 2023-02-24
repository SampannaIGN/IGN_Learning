/*
Program which optimally pushes 10 integer values into the vector
*/
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void fill(vector <T>&my_vector){
    my_vector.reserve(10);//to allocate 10 blocks of memory so that it doesn't keep expanding 2x all the time
    cout<<"Please enter 10 integer values to push in the vector"<<endl;
    for(int i = 0; i < 10; i    ++){
        T value;
        cout<<"Enter integer value "<<(i+1)<<") ";
        cin>>value;
        my_vector.emplace_back(value);
        //in case of objects it directly creates it in the vector which makes it efficient
    }
}

template <typename T>
void display(vector <T>&my_vector){
    cout<<"Elements in the vector are = [ ";
    for(const T &value:my_vector){
        cout<<value<<" ";
    }
    cout<<"]"<<endl;
}

void solution(){
    vector <double>my_vector;
    fill(my_vector);
    display(my_vector);
}

int main(){
    solution();
    return 0;
}