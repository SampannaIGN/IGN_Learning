#ifndef _MY_ARRAY_H
#define _MY_ARRAY_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory>

using namespace std;

template <typename T>
class my_array{
    private:
        unique_ptr <unique_ptr<T[]>[]>input_ptr1;
        unique_ptr <unique_ptr<T[]>[]>input_ptr2;
        size_t row;
        size_t col;

    public:
        my_array();
        my_array(size_t row, size_t col);

        static T get_random_value(int min, int max);
        void init(size_t row, size_t col);//initializes the arrays with given row and col
        void fill_arr1();//fills the first array
        void fill_arr2();//fills the second array
        void display_arr1();//displays the first array
        void display_arr2();//displays the second array
        void display_ED();//displays the euclidean distance
        /*displays the max pool array for given window size & stride*/
        void display_MP_arr1(   size_t window_size_row,
                                size_t window_size_col, 
                                size_t stride_row,
                                size_t stride_col);
        
        ~my_array();
    private:
        void allocate_memory();//allocates memory for two 2D arrays
        /*Returns the max from (row,col) for given window_size_row & window_size_col*/
        T get_max_arr1(size_t row, size_t col, size_t window_size_row, size_t window_size_col);
};

#endif