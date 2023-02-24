#include <iostream>
#include <vector>

using namespace std;

enum my_enum{one,two=6,three,four};//unscoped enum
//Disadvantage is you can't use one,two three again

enum class my_class_enum{one,two,three,four};//scoped enum

void unscoped_enum(){
    my_enum enumObj1 = three;
    my_enum enumObj2 = four;
    my_enum enumObj3 = one;

    vector <my_enum>my_vector;
    my_vector.push_back(my_enum(4));
    my_vector.push_back(my_enum(10));//invalid but works fine
    my_vector.push_back(enumObj1);
    my_vector.push_back(enumObj2);
    my_vector.push_back(enumObj3);
   // my_vector.push_back(3); Error

    for(auto value:my_vector)cout<<value<<" ";
    cout<<endl; 
}

void scoped_enum(){
    my_class_enum enumObj1 = my_class_enum::three;
    my_class_enum enumObj2 = my_class_enum::four;
    my_class_enum enumObj3 = my_class_enum::one;

    vector <my_class_enum>my_vector;
    my_vector.push_back(my_class_enum(4));
    my_vector.push_back(my_class_enum(10));//invalid but works fine
    my_vector.push_back(enumObj1);
    my_vector.push_back(enumObj2);
    my_vector.push_back(enumObj3);
   // my_vector.push_back(3); Error

    for(auto value:my_vector)cout<<static_cast<int>(value)<<" ";
    cout<<endl;
}

int main(){
    //unscoped_enum();
    scoped_enum();
    return 0;
}