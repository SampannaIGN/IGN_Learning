/*
Problem in brief =>
Create 2 arrays of size given by user and generate
random values and store them in these 2 arrays
Finally calculate the eucledian distance and print them
*/
#include <iostream>
#include <memory>
#include <iomanip>
#include <cmath>
#include "my_array.cpp"

using namespace std;

//Generates random values between min and max
int get_random_value(int min, int max){
    int random_value = rand()%(max-min+1)+min;
    return random_value;
}

//Displays the 2D array elements
void display(unique_ptr <unique_ptr<int[]>[]>&arr_ptr,
                int row,
                int col){
    cout<<endl; 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<setw(5)<<left<<arr_ptr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Calculates the eucledian distance and displays
void displayED(unique_ptr <unique_ptr<int[]>[]>&arr_ptr1,
                unique_ptr <unique_ptr<int[]>[]>&arr_ptr2,
                int row,
                int col){
    cout<<endl; 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int x = arr_ptr1[i][j];
            int y = arr_ptr2[i][j];
            double euclidean_dis = sqrt(abs(x*x-y*y));
            cout<<setw(8)<<left<<fixed<<setprecision(2)<<euclidean_dis<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Returns unique_ptr for 2D array
unique_ptr <unique_ptr<int[]>[]> get_ptr(int row, int col){
    unique_ptr <unique_ptr<int[]>[]>arr_ptr = nullptr;
    try{
        arr_ptr = make_unique<unique_ptr<int[]>[]>(row);
        for(int i = 0; i < row; i++){
            arr_ptr[i] = make_unique<int[]>(col);
        }
        return arr_ptr;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
        exit(1);
    }
}

//Fills the 2D array with random values
void fill_array(unique_ptr <unique_ptr<int[]>[]>&arr_ptr,
                int row,
                int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr_ptr[i][j] = get_random_value(1,20); 
        }
    }
}

//Solution the problem
void solution(){
    int row,col;

    cout<<"Enter number of rows = ";
    cin>>row;
    cout<<"Enter number of cols = ";
    cin>>col;
    
    /*Creating new 2D array*/
    unique_ptr <unique_ptr<int[]>[]>arr_ptr1 = nullptr;
    unique_ptr <unique_ptr<int[]>[]>arr_ptr2 = nullptr;
    
    arr_ptr1 = get_ptr(row,col);
    arr_ptr2 = get_ptr(row,col);

    srand(time(0));
    /*Fill the array with random values*/
    fill_array(arr_ptr1,row,col);
    fill_array(arr_ptr2,row,col);

    cout<<"Randomly generated array1 elements are"<<endl;
    display(arr_ptr1,row,col);
    cout<<"Randomly generated array2 elements are"<<endl;
    display(arr_ptr2,row,col);

    /*Displaying the Eucledian distance*/
    cout<<"Eucledian distance b/w array1 & array2 is"<<endl;
    displayED(arr_ptr1,arr_ptr2,row,col);
}

int main(){
    solution();
    return 0;
}