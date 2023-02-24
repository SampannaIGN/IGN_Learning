#ifndef _MY_ARRAY_H
#define _MY_ARRAY_H

#include <iostream>
#include "my_array_util.h"

using namespace std;

template <typename I,typename O>
class my_array{
    private:
    unique_ptr <I[]>input_ptr;
    unique_ptr <O[]>output_ptr;
    size_t size;
    
    public:
    my_array();
    my_array(size_t size);

    void init(size_t size);//initializes input_ptr with user entered values
    const I * get_input()const;//Returns the input pointer which can't be modified
    const O * get_output()const;//Returns the output pointer which can't be modified
    
    ~my_array();

    private:
    void compute_output();//performs operation on arr and updates output_ptr

    template<class I_, class O_>
    friend ostream& operator<<(ostream &sout, const my_array<I_,O_> &obj);
};



#endif