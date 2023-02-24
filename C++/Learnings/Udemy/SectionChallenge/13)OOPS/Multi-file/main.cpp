#include <iostream>
#include "source.h"

using namespace std;

void print(Example &my_example){
    cout<<"var = "<<my_example.getVar()<<endl;
    cout<<"str = \""<<my_example.getStr()<<"\""<<endl;
}
int main()
{
    Example my_example;  
    print(my_example); 

    my_example.setStr("New string");
    my_example.setVar(20);
    print(my_example);

    return 0;
}

//cmd => g++ source.cpp main.cpp -o main
//       ./main
//Note => no need source.h as #include "source.h" will call it.