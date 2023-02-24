/*
Check if a string is palindrome or not using deque
*/
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

bool is_palindrome(string &input){
    deque <char>my_deque;
    copy_if(input.begin(),input.end(),back_inserter(my_deque),
    [](char ch){return isalpha(ch);});

    /*for_each(my_deque.begin(),my_deque.end(),[](char ch){cout<<ch<<" ";});
    cout<<endl;*/
    while(my_deque.size()>1){
        char first = my_deque.back();
        char last = my_deque.front();
        if(first != last)return false;
        my_deque.pop_back();
        my_deque.pop_front();
    }
    return true;
}

void solution(){
    string input;
    cout<<"Enter a string to check if it is palindrome or not"<<endl;
    getline(cin,input,'\n');

    for(int i = 0; i < input.length(); i++)input[i]=toupper(input[i]);
    
    if(is_palindrome(input))cout<<"This is a palindrome.";
    else cout<<"This is not a palindrome.";
    cout<<"\n";
}

int main(){
    solution();
    return 0;
}