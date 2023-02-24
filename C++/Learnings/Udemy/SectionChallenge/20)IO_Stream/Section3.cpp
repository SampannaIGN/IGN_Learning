/*

*The task is to count number of words in a file.

*/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void update_count(string word, string search_str, size_t &count){
    if(word.length() < search_str.length())return;

    size_t index = 0;
    while((index=word.find(search_str,index)) != string::npos){
        count++;
        index++;
    }
}

void solution(){
    ifstream input_file;
    input_file.open("Files//romeoandjuliet.txt");

    if(!input_file){
        cerr<<"Error opening the file"<<endl;
        return;
    }
    
    string word;
    string search_str;
    size_t count = 0;
    
    cout<<"Enter word to search = ";
    cin>>search_str;

    while(!input_file.eof()){
        input_file>>word;
        update_count(word,search_str,count);
    }
    cout<<"Number of words found are "<<count<<endl;
    input_file.close();
}

int main(){
    solution();
    return 0;
}