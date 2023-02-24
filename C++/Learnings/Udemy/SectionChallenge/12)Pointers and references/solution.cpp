#include <iostream>

using namespace std;

int * multiply_all(int arr1[] , int arr2[], int size1, int size2){
    int *result = new int[size1*size2];
    int index = 0;

    for(int i = 0; i < size2; i++){
        for(int j = 0; j < size1; j++){
            result[index] = arr2[i] * arr1[j];
            index++;
        }
    }
    return result;
}

void print(int *ptr, int size){
    for(int i = 0; i < size; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

void array_operation(){
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {10,20,30};

    int size1 = sizeof(arr1)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);

    int *product_array = multiply_all(arr1,arr2,size1,size2);

    print(product_array,size1*size2); 

    delete []product_array;
}

int main(){
    array_operation();
    return 0;
}
