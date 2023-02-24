#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool is_palindrome(string &str){

    stack <char>my_stack;
    queue <char>my_queue;

    for(int i = 0; i < str.length(); i++){
        char ch = str.at(i);
        if(isalpha(ch)){
            my_queue.push(toupper(ch));
            my_stack.push(toupper(ch));
        }
    }

    while(!my_stack.empty()){
        char ch1 = my_stack.top();
        char ch2 = my_queue.front();
        my_stack.pop();
        my_queue.pop();
        if(ch1!=ch2)return false;
    }
    return true;
}

void solution(){
    cout<<"Enter a string to check if it is a palindrome or not = ";
    string input;
    cin>>input;

    if(is_palindrome(input))
        cout<<"Entered string is palindrome"<<endl;
    else
        cout<<"Entered stirng is not palindrome"<<endl;
    
}

int main(){
    solution();
    return 0;
}