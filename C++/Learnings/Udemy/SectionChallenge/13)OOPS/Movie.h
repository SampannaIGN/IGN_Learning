#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <vector>

using namespace std;

class Movie{
    private:
    string name;
    string rating;
    int watch_count;

    static bool rating_init_flag;           //ensure rating option is set only once
    static vector <string>rating_option;    //rating options available for user

    public:
    Movie(string name, string rating, int watch_count);

    string get_name();
    string get_rating();
    int get_watch_count();
    void set_all(string name, string rating, int watch_count);
    void inc_watch_count();
    
    static void split_str(vector <string>&result, string input, char ch);
    static bool is_rating_valid(string rating);
    static void set_rating_option();
};


#endif