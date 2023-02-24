#include "Movies.h"

void Movies::add_movie(string name, string rating, int watch_count){

    Movie new_movie(name,rating,watch_count);

    /*Check if movie already exists*/
    for(Movie &movie:movie_list){
        if(movie.get_name() == name){
            cout<<name<<" movie "<<name<<" already exists"<<endl;
            return;
        }
    }

    /*Check if the rating is valid*/
    if(!Movie::is_rating_valid(rating)){
        cout<<"Rating value for "<<name<<" movie doesn't exist..."<<endl;
        return;
    }

    /*add movie if the condition is satisfied*/
    movie_list.push_back(new_movie);
}

void Movies::display(){
    cout<<"Movies in the list are =>"<<endl;
    for(Movie &movie:movie_list){
        cout<<"{name = "<<movie.get_name()<<",rating = "<<movie.get_rating()<<",watch count = "<<movie.get_watch_count()<<"}\n";
    }
}

void Movies::inc_watch_count(string name){
    for(Movie &movie:movie_list){
        if(movie.get_name() == name){
            movie.inc_watch_count();
            return;
        }
    }
    cout<<"Movie "<<name<<" doesn't exist please add the movie"<<endl;
}

ostream& operator<<(ostream& os, const Movies &movies){
    os<<"Movies in the list are =>"<<endl;
    for(Movie movie:movies.movie_list){
        os<<"{name = "<<movie.get_name()<<",rating = "<<movie.get_rating()<<",watch count = "<<movie.get_watch_count()<<"}\n";
    }
    os<<endl;
    return os;
}