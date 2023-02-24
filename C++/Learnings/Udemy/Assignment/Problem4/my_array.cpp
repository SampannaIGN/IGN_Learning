#include "my_array.h"

template <typename T>
my_array<T>::my_array():size{0},arr_ptr{nullptr}{}

template <typename T>
my_array<T>::my_array(size_t size):size{size}{
    try{
        arr_ptr = new T[size];
        fill_array();
    }
    catch(...){
        this->size = 0;
        arr_ptr = nullptr;
        cout<<"Couldn't allocate memory"<<endl;
    }
}

template <typename T>
void my_array<T>::fill_array(){
    for(size_t i = 0; i < size; i++)
        arr_ptr[i] = static_cast<T>(i);
}

template <typename T>
const T * my_array<T>::get_array()const{
    return arr_ptr;
}

template <typename T>
ostream& operator<<(ostream &sout,const my_array <T>&obj){
    if(obj.arr_ptr == nullptr){
        sout<<"[]"<<endl;
        return sout;
    }
    sout<<"[";
    for(int i = 0; i < obj.size; i++){
        sout<<obj.arr_ptr[i];
        if(i!=obj.size-1)sout<<",";
    }
    sout<<"]"<<endl;
    return sout;
}

template <typename T>
my_array<T>::~my_array(){
    delete []arr_ptr;
}