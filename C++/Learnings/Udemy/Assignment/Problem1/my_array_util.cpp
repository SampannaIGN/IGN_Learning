#include "my_array_util.h"

template <typename T>
T my_array_util<T>::get_max(T *ptr, size_t size){
    if(size <= 0)throw invalid_argument("invalid size");
    if(ptr == nullptr)throw runtime_error("pointer can't be null");

    T max = ptr[0];

    for(int i = 1; i < size; i++)
        if(ptr[i] > max)max = ptr[i];

    return max;
}

template <typename T>
void my_array_util<T>::fill_array(T *ptr, size_t size){
    for(int i = 0; i < size; i++){
        T value;
        cout<<"Enter element "<<(i+1)<<") ";
        cin>>value;
        ptr[i] = value;
    }
}

template <typename T>
unique_ptr<T[]> my_array_util<T>::get_unique_ptr(T type,size_t size){
    try{
        //T *ptr = new T[size]; //Have to delete on your own
        unique_ptr <T[]>arr_ptr = make_unique<T[]>(size);
        return arr_ptr;
    }
    catch(exception &e){
        cerr<<e.what()<<endl;
        exit(1);
    }
}

