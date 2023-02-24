#include "my_array.h"

template <typename T>
my_array<T>::my_array():row{0},col{0},input_ptr1{nullptr},input_ptr2{nullptr}{}

template <typename T>
my_array<T>::my_array(size_t row, size_t col):row{row},col{col}{
    init(row,col);
}

template <typename T>
void my_array<T>::init(size_t row, size_t col){
    this->row = row;
    this->col = col;
    input_ptr1 = nullptr;
    input_ptr2 = nullptr;
    allocate_memory();
    fill_arr1();
    fill_arr2();
}

template <typename T>
T my_array<T>::get_random_value(int min, int max){
    T random_value = static_cast<T>(rand()%(max-min+1)+min);
    return random_value;
}

template <typename T>
void my_array<T>::fill_arr1(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            input_ptr1[i][j] = get_random_value(1,20); 
        }
    }
}

template <typename T>
void my_array<T>::fill_arr2(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            input_ptr2[i][j] = get_random_value(1,20); 
        }
    }
}

template <typename T>
void my_array<T>::display_arr1(){
    cout<<endl; 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<setw(8)<<left<<fixed<<setprecision(2)<<input_ptr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template <typename T>
void my_array<T>::display_arr2(){
    cout<<endl; 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<setw(8)<<left<<fixed<<setprecision(2)<<input_ptr2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template <typename T>
void my_array<T>::display_ED(){
    cout<<endl; 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            T x = input_ptr1[i][j];
            T y = input_ptr2[i][j];
            double euclidean_dis = sqrt(abs(x*x-y*y));
            cout<<setw(8)<<left<<fixed<<setprecision(2)<<euclidean_dis<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template <typename T>
void my_array<T>::display_MP_arr1(size_t window_size_row, size_t window_size_col, size_t stride_row, size_t stride_col){
    cout<<endl; 
    for(size_t i = 0; i < row; i = i+stride_row){
        for(size_t j = 0; j < col; j = j+stride_col){
            T value = input_ptr1[i][j];
            T max = get_max_arr1(i,j,window_size_row,window_size_col);
            cout<<setw(8)<<left<<fixed<<setprecision(2)<<max<<" ";
        }
        cout<<endl;
    }
    cout<<endl; 
}

template <typename T>
T my_array<T>::get_max_arr1(size_t row, size_t col, size_t window_size_row, size_t window_size_col){
    size_t row_end = row+window_size_row;
    size_t col_end = col+window_size_col;
    size_t row_max = (this->row < row_end)?this->row:row_end;
    size_t col_max = (this->col < col_end)?this->col:col_end;
    T max = input_ptr1[row][col];
    for(size_t i = row; i < row_max; i++){
        for(size_t j = col; j < col_max; j++){
            if(input_ptr1[i][j] > max)max = input_ptr1[i][j];
        }
    }
    return max;
}

template <typename T>
void my_array<T>::allocate_memory(){
    try{
        input_ptr1 = make_unique<unique_ptr<T[]>[]>(row);
        for(int i = 0; i < row; i++)input_ptr1[i] = make_unique<T[]>(col);
        input_ptr2 = make_unique<unique_ptr<T[]>[]>(row);
        for(int i = 0; i < row; i++)input_ptr2[i] = make_unique<T[]>(col);
    }
    catch(...){
        cerr<<"Exception allocating memory"<<endl;
        exit(1);
    }
    
}

template <typename T>
my_array<T>::~my_array(){
    input_ptr1.reset();
    input_ptr2.reset();
}