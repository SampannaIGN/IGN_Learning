#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include "Movie.h"

using namespace std;

class Movies{
    private:
    vector <Movie>movie_list;

    public:
    void add_movie(string name, string rating, int watch_count = 0);
    void display();
    void inc_watch_count(string name);
    friend ostream& operator<<(ostream& os, const Movies &movies);
};

#endif