#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int i = 0, int j = 0) {
        x = i; y = j;
        cout<<this<<endl;
        cout<<"constructor"<<endl;
    }

    Point(const Point &p){
        cout<<"copy constructor"<<endl;
    }
    void print() {
        cout << "x = " << x << ", y = " << y << '\n';
    }
};


int main() {
    Point t(20,10);
    t.print();
    t = 30; // tempory object is created which is then assigned to t    
    t.print();
    return 0;
}