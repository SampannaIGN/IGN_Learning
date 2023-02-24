/*
implement string class and overloading folowing functions
unary-  => to lowercase
unary+  => to uppercase
!=      => return true to check if two strings are not equal
<       => return true if first string is lexically less than second
>       => return true if first string is lexically greater than second
+       => concatenation of two string
+=      => same "        "           "
str*(3) => ex: if str = "abc" then it should do "abcabcabc"
*=      => same "        "           "
*/

#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <cstring>

using namespace std;

class my_string{
    private:
        char *ptr;
        size_t size;
    
    public: 
        my_string();
        my_string(size_t size);
        my_string(const char *ptr);
        my_string(const string &str);
        my_string(const my_string &that);

        size_t length();
        my_string& to_upper();
        my_string& to_lower();
        bool is_equal(const my_string &that);
        bool is_greater(const my_string &that);
        bool is_lesser(const my_string &that);
        my_string& concat(const my_string &that);
        my_string& multiply(int times);

        my_string& operator-();
        my_string& operator+();
        bool operator!=(const my_string &that);
        bool operator==(const my_string &that);
        bool operator<(const my_string &that);
        bool operator>(const my_string &that);
        my_string& operator+=(const my_string &that);

        friend ostream& operator<<(ostream &sout, my_string &that);
        friend istream& operator>>(istream &sin, my_string &that);

        ~my_string();
};

#endif