#include <iostream>

using namespace std;

class Parent{
    private:
    double x;

    public:
    Parent(){}

    Parent(double x){
        this->x = x;
    }

    void display(){
        cout<<"x="<<this->x<<endl;
    }
};

class Derived:public Parent{
    using Parent::Parent;//if no constructor matches in Derived Parent constructor is called
    private:
    int y;

    public:
    Derived(int y){//Can use Derived(int y):Parent{y}{...} to call Parent constructor
        this->y = y;
    }

    void display(){
        cout<<"y="<<this->y<<endl;
    }
};


int main(){
    return 0;
}