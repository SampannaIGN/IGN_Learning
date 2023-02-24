#ifndef _MY_ARRAY_H
#define _MY_ARRAY_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class my_array{
    private:
    T *arr_ptr;
    size_t size;

    public:
    my_array();//Constructor to initialize size to 0 & arr_ptr to null
    my_array(size_t size);//Constructor to initialize size to given size & allocate memory 
    const T * get_array()const;//return arr_ptr whose value can't be modified

    private:
    void fill_array();//sets value of element 0-(N-1)
    
    template <typename T_>
    friend ostream& operator<<(ostream &sout,const my_array <T_>&obj);//prints elements of array

    public:
    ~my_array();//clears the memory pointed by arr_ptr
};

#endif