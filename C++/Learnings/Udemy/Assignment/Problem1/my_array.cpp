#include "my_array.h"

template <typename I, typename O>
my_array<I,O>::my_array() : input_ptr{nullptr}, output_ptr{nullptr}, size{0}{}

template <typename I, typename O>
my_array<I,O>::my_array(size_t size){
    init(size);
}

template <typename I, typename O>
void my_array<I,O>::init(size_t size){
    I input_type;O output_type;
    
    input_ptr.reset();
    output_ptr.reset();
    
    input_ptr = my_array_util<I>::get_unique_ptr(input_type,size);
    output_ptr = my_array_util<O>::get_unique_ptr(output_type,size);

    my_array_util<I>::fill_array(input_ptr.get(),size);
    this->size = size;
    compute_output();    
}

template <typename I, typename O>
void my_array<I,O>::compute_output(){
    I max_value = my_array_util<I>::get_max(input_ptr.get(),size);
    for(int i = 0; i < size; i++)
        output_ptr[i] = static_cast<O>(input_ptr[i])/max_value;
}

template <typename I, typename O>
const I * my_array<I,O>::get_input()const{
    return input_ptr.get();
}

template <typename I, typename O>
const O * my_array<I,O>::get_output()const{
    return output_ptr.get();
}

template <typename I, typename O>
my_array<I,O>::~my_array(){
    input_ptr.reset();
    output_ptr.reset();
}


template <typename I, typename O>
ostream& operator<<(ostream &sout, const my_array<I,O> &obj){
    if(obj.input_ptr == nullptr || obj.output_ptr == nullptr)return sout<<"[]";
    const I *input = obj.get_input(); 
    sout<<"input elements are = ";
    sout<<"[";
    for(int i = 0; i < obj.size; i++)sout<<input[i]<<" ";
    sout<<"]"<<endl;

    const O *output = obj.get_output();
    sout<<"output elements are = ";
    sout<<"[";
    for(int i = 0; i < obj.size; i++)sout<<output[i]<<" ";
    sout<<"]";
    return sout;
}