#include <iostream>

using namespace std;

void ask_favorite_number(){
    int number;
    cout<<"Enter you favourite number between 1 & 100 = ";
    cin>>number;

    cout<<"Amazing that's my favorite number too!"<<endl;
    cout<<"No really! "<<number<<" is my favorite number"<<endl;
}

int main()
{
    ask_favorite_number();
    return 0;
}
