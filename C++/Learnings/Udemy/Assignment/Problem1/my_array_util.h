#ifndef _MY_ARRAY_UTIL_H
#define _MY_ARRAY_UTIL_H

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class my_array_util{
    public:
    static T get_max(T *ptr, size_t size);//returns the max from array pointed by ptr
    static void fill_array(T *ptr, size_t size);//fills array with values entered by user
    static unique_ptr<T[]> get_unique_ptr(T type,size_t size);//returns unique_ptr for any array
};


#endif