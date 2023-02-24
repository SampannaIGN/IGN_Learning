/*
Outline

Create Movie class which has following attributes representing=>
1)movie name
2)movie rating (can be G,PG,PG-13,R)
3)watch count

Create Movies class which has following functions=>
1)add movie by providing movie name, rating & watched count
2)increment the watched count of a movie
3)Display all movies

*/
#include <iostream>
#include "Movies.h"

using namespace std;

void movie_list_initialization(){
    Movies movie_list;
    vector <string>movie_paramters;
    string input;
    int movies_count;
    
    Movie::set_rating_option();

    cout<<"How many movies do you want to include = ";
    cin>>movies_count;

    cout<<"Enter names of movies line by line => "<<endl;

    string name,rating;
    int watch_count;

    //ask user to enter movie information
    for(int i = 0; i < movies_count; i++){
        cout<<(i+1)<<"."<<endl;
        cout<<"Enter movie name => ";
        cin.clear();
        cin.ignore();
        getline(cin,name,'\n');
        cout<<"Enter movie rating => ";
        cin>>rating;
        cout<<"Enter number of times you watched the movie => ";
        cin>>watch_count;
        
        movie_list.add_movie(name,rating,watch_count);
        cout<<endl;
    }

    //display movie list because of overloading << operator 
    cout<<movie_list;

    cout<<"Do you want to increment any movie count?(y/n)";
    cin>>name;

    //check for incrementing rating
    if(name == "y"){    
        cout<<"which movie to increment"<<endl;
        cin.clear();
        cin.ignore();
        getline(cin,name,'\n');
        movie_list.inc_watch_count(name);
        movie_list.display();
    }
    else if(name == "n"){
        cout<<"Program Terminated successfully!!!"<<endl;
    }
    else{
        cout<<"Program Terminated abnormally!!!"<<endl;
    }
}

int main(){
    movie_list_initialization();
    return 0;
}