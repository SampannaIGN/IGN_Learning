#include "Movie.h"  

bool Movie::rating_init_flag = false;
vector <string>Movie::rating_option;

void Movie::split_str(vector <string>&result, string input, char ch){
    //trim front part of input
    long unsigned int index = 0;
    while((index<input.length()) && (input.at(index) == ch))index++;
    if(index>=input.length() || input.length() == 0)return;
    input = input.substr(index);
    index = 0;

    string split_str = "";
    long unsigned int length = input.length();
    
    //put the split values into split_str & push it back to the vector
    for(long unsigned int i = 0; i < length; i++){
        if(input.at(i) == ch){
            result.push_back(split_str);
            split_str = "";
            while((i<length) && (input.at(i) == ch))i++;
            i--;
        }
        else{
            split_str += input.at(i);
        }
    }
    if(split_str.length()!= 0)result.push_back(split_str);
}

bool Movie::is_rating_valid(string rating){
    for(string &cur_rating:rating_option){
        if(cur_rating == rating)return true;
    }
    return false;
}

void Movie::set_rating_option(){
    if(!rating_init_flag){
        string input;
        cout<<"Enter rating options in space separated fashion = ";
        getline(cin,input,'\n');
        split_str(Movie::rating_option,input,' ');
        rating_init_flag = true;
    }
}

Movie::Movie(string name, string rating, int watch_count){
    set_rating_option();
    set_all(name,rating,watch_count);
}

void Movie::set_all(string name, string rating, int watch_count){
    this->name = name;
    this->rating = rating;
    this->watch_count = watch_count;        
}

void Movie::inc_watch_count(){
    this->watch_count++;
}

string Movie::get_name(){
    return name;
}

string Movie::get_rating(){
    return rating;
}

int Movie::get_watch_count(){
    return watch_count;
}