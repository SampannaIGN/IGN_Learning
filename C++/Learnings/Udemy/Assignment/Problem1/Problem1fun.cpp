/*
Problem in brief=>
    Given arr = {3,2,6,1,4,7,8,5,9,10}

return array such that each element is element/max{arr}
    i.e. result = {0.3,0.2....}
*/

#include <iostream>
#include <memory>

using namespace std;

//Displays the contents pointed by the ptr
template <class T>
void display(const T *ptr, int size){
    cout<<"[";
    for(int i = 0; i < size; i++){
        cout<<" "<<ptr[i]<<" ";
        if(i!=size-1)cout<<",";
    }
    cout<<"]"<<endl;
}

//Returns int array pointer that points to array of given size 
template <class T>
unique_ptr<T[]> get_array_ptr(T type,int size){
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

//Fills the array with user entered values
template <class T>
T * fill_array(T *ptr, int size){
    for(int i = 0; i < size; i++){
        T value;
        cout<<"Enter element "<<(i+1)<<") ";
        cin>>value;
        ptr[i] = value;
    }
    return ptr;
}

//Returns resultant double array
double * get_result_array(  const int *array_ptr,
                            double *result_ptr,
                            int max_value,
                            int size){
    try{
        for(int i = 0; i < size; i++){
            result_ptr[i] = static_cast<double>(array_ptr[i])/max_value;
        }
        return result_ptr;
    }
    catch(exception &e){
        cerr<<e.what()<<endl;
        exit(1);
    }
}

//Returns the max value from int array
template <class T>
T get_max(T *ptr, int size){
    if(size <= 0){
        throw invalid_argument("invalid size");
    }
    int max = ptr[0];

    for(int i = 0; i < size; i++)
        if(ptr[i] > max)max = ptr[i];

    return max;
}

//solution to the problem
void solution(){
    /*Get the number of elements in array*/
    int size;
    cout<<"Enter number of elements of the array = ";
    cin>>size;

    /*Initializing the array and display*/
    
    unique_ptr <int[]>unique_input_ptr = get_array_ptr(0,size);
    int *input_ptr = unique_input_ptr.get();
    
    input_ptr = fill_array(input_ptr,size);
    cout<<"Input array elements are = ";
    display(input_ptr,size);

    /*Result array*/
    int max_value = get_max(input_ptr,size);
    
    unique_ptr <double[]>unique_double_ptr = get_array_ptr(0.0,size); 
    double *output_ptr = unique_double_ptr.get();

    output_ptr = get_result_array(input_ptr,output_ptr,max_value,size);
    cout<<"Output array elements are = ";
    display(output_ptr,size);
}


int main(){
    solution();
    return 0;
}
