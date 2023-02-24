#include <iostream>

using namespace std;

void syntax(){
    int value1 = []()->int{return 10;}();
    cout<<value1<<endl;
    class Abc{
        public:
        Abc(){cout<<"default constructor"<<endl;}
        int operator()(int x){return x*x;}
    };

    Abc obj;//default constructor is called
    int value2 = obj(4);//obj.operator()(4) is called
    cout<<value2<<endl;

    int value3 = [](int x)->int{return x;}(30);
    cout<<value3<<endl;

    auto fun1 = [](int x)->int{return x*x*x;};
    cout<<fun1(3)<<endl;

    auto fun2 = [](auto x)->auto{return x*x;};
    cout<<fun2(3.2)<<endl;
    cout<<fun2(4.1)<<endl;
}

void lambda_functions(){

}

int main(){
    //syntax();
    lambda_functions();
    return 0;
}