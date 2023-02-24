#include "my_string.h"

my_string::my_string(){
    this->ptr = nullptr;
    this->size = 0;
}

my_string::my_string(size_t size){
    this->size = size;
    this->ptr = new char[size];
}

my_string::my_string(const char *ptr){
    this->size = strlen(ptr);
    this->ptr = new char[size];
    strcpy(this->ptr,ptr);
}

my_string::my_string(const string &str){
    this->size = str.length();
    this->ptr = new char[size];
    for(int i = 0; i < this->size; i++){
        ptr[i] = str.at(i);
    }
}

my_string::my_string(const my_string &that){
    this->size = that.size;
    strcpy(this->ptr,that.ptr);
}

size_t my_string::length(){
    return size;
}

my_string& my_string::to_upper(){
    for(int i = 0; i < this->size; i++){
        if(ptr[i]>='a' && ptr[i]<='z')
            ptr[i]=static_cast<char>(ptr[i]-('a'-'A'));
    }
    return *this;
}

my_string& my_string::to_lower(){
    for(int i = 0; i < this->size; i++){
        if(ptr[i]>='A' && ptr[i]<='Z')
            ptr[i]=static_cast<char>(ptr[i]+('a'-'A'));
    }
    return *this;
}

bool my_string::is_equal(const my_string &that){
    return (strcmp(this->ptr,that.ptr)==0)?true:false;
}

bool my_string::is_greater(const my_string &that){
    return (strcmp(this->ptr,that.ptr)>0)?true:false;
}

bool my_string::is_lesser(const my_string &that){
    return (strcmp(this->ptr,that.ptr)<0)?true:false;
}

my_string& my_string::concat(const my_string &that){
    char *new_ptr = new char[size+that.size];
    strcpy(new_ptr,ptr);
    delete []ptr;

    for(int i = size; i < size+that.size; i++)
        new_ptr[i] = that.ptr[i-size];

    ptr = new_ptr;
    size += that.size;

    return *this;
}

my_string& my_string::multiply(int times){
    char *new_ptr = new char[size*times];
    strcpy(new_ptr,ptr);

    for(int i = 0; i < size*times; i++)
        new_ptr[i] = ptr[i%size];

    delete []ptr;

    ptr = new_ptr;
    size *= times;

    return *this;
}

my_string& my_string::operator-(){
    return to_lower();
}

my_string& my_string::operator+(){
    return to_upper();
}

bool my_string::operator!=(const my_string &that){
    return !is_equal(that);
}

bool my_string::operator==(const my_string &that){
    return is_equal(that);
}

bool my_string::operator<(const my_string &that){
    return is_lesser(that);
}

bool my_string::operator>(const my_string &that){
    return is_greater(that);
}

my_string& my_string::operator+=(const my_string &that){
    return concat(that);
}

ostream& operator<<(ostream &sout, my_string &that){
    for(int i = 0; i < that.size; i++){
        sout<<that.ptr[i];
    }
    return sout;
}

istream& operator>>(istream &sin, my_string &that){
    string input;
    sin>>input;
    
    delete []that.ptr;
    that.ptr = new char[input.length()];
    that.size = input.length();

    for(int i = 0; i < that.size; i++)
        that.ptr[i] = input.at(i);

    return sin;
}

my_string::~my_string(){
    delete []ptr;
}