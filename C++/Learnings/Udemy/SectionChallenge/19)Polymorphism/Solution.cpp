#include <iostream>

using namespace std;

class Parent{
    private:
        int x;
    public:
    Parent(){cout<<"Parent constructor"<<endl;}
    Parent(int x):x(x){cout<<"Parent construct(x)"<<endl;}
    void method(){
        cout<<"Parent method"<<endl;
    }
    ~Parent(){cout<<"Parent destructor"<<endl;}
};

class Child: public Parent{
    private:
        double y;
    public:
    Child(){cout<<"Child constructor"<<endl;}
    void method(){
        cout<<"Child method"<<endl;
    }
    Child(double y){cout<<"Child constructor(x)"<<endl;}
    ~Child(){cout<<"Child destructor"<<endl;} 
};

int main(){
    
    return 0;
}