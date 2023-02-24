#include <iostream>

using namespace std;

class Example{
    public:
        int x;double y;string str;
    /* Case1
    Example(){
        this->x = 0;
        this->y = 0.0;
        this->str = "";
    }
    
    Example(int x, double y){
        this->x = x;
        this->y = y;
        this->str = "";
    }

    Example(int x, double y, string str){
        this->x = x;
        this->y = y;
        this->str = str;
    }*/

    /*case2
    Example(): Example{0,0.0,""}{}
    Example(int x, double y): Example{x,y,""}{}
    Example(int x, double y, string str): x{x},y{y},str{str}{}
    */
    //case3 =>recommended
    Example(int x = 0, double y = 0.0, string str = ""):x{x},y{y},str{str}{}

};

int main(){
    Example ex1(12);            cout<<ex1.x<<" "<<ex1.y<<" "<<ex1.str<<endl;
    Example ex2(10,15.5);           cout<<ex2.x<<" "<<ex2.y<<" "<<ex2.str<<endl;
    Example ex3(10,20.2,"abc");     cout<<ex3.x<<" "<<ex3.y<<" "<<ex3.str<<endl;
    return 0;
}
