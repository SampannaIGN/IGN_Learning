#include <iostream>
#include "../Problem2/my_array.cpp"

using namespace std;

void solution(){
    srand(time(0));

    /*Entering row,col values of 2D arrays to be created*/
    size_t row;
    size_t col;
    cout<<"Enter number of rows = ";
    cin>>row;
    cout<<"Enter number of cols = ";
    cin>>col;

    /*Creating my_array object which creates two 2D arrays filled with random values*/
    my_array <double>obj(row,col);
    cout<<"Array1 is ";
    obj.display_arr1();
    cout<<"Array2 is ";
    obj.display_arr2();
    
    /*Getting necessary info for max pooling from user*/
    cout<<"Let's perform max pooling"<<endl;
    
    cout<<"Enter height & width of window = ";
    size_t height,width;
    cin>>width>>height;
    cout<<"Enter row stride & col stride value = ";
    size_t row_stride,col_stride;
    cin>>row_stride>>col_stride;
    cout<<"Max pool result is "<<endl;
    //obj.display_MP_arr1(2,2,1,1);
    obj.display_MP_arr1(height,width,row_stride,col_stride);

}

int main(){
    solution();
    return 0;
}