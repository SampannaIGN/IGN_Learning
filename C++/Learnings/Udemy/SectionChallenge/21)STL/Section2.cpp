/*
Choose among the following options 
F -> Play first song
N -> Play next song
P -> Play previous song
A -> Add new song   
L -> List the current playlist

Use doubly linked list to implement the above
Note=> In case you reach the end try to circle through the playlist
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>

using namespace std;

class music_player{
    private:
        list <pair<string,string>>songs;
        list<pair<string,string>>::iterator itr;
    
    public:
        music_player():itr{songs.end()}{}
        music_player(list <pair<string,string>>&songs):music_player(){
            this->songs.assign(songs.begin(),songs.end());
        }

        void add_song(string title, string name){
            this->songs.push_back({title,name});
            cout<<"song added to the playlist successfully"<<endl;
        }

        void first_song(){
            if(is_empty()){cout<<"Please add songs to playlist"<<endl;return;}
            itr = songs.begin();
            cout<<"Playing song => "<<(*itr).first<<" = "<<(*itr).second<<endl;
        }

        void previous_song(){
            if(is_empty()){cout<<"Please add songs to playlist"<<endl;return;}
            if(itr != songs.begin()){itr--;}
            else{itr = songs.end();itr--;}
            play_song();
        }

        void next_song(){
            if(is_empty()){cout<<"Please add songs to playlist"<<endl;return;}

            if(itr != songs.end())itr++;
            if(itr == songs.end())itr = songs.begin();
            play_song();
        }

    private:
        bool is_empty(){
            return (this->songs.size()==0);
        }
        
        void play_song(){
            cout<<"Playing song => "<<(*itr).first<<" = "<<(*itr).second<<endl;
        }

        friend ostream& operator<<(ostream &sout, const music_player &obj){
        for(const pair <string,string>&value:obj.songs){
            sout<<setw(10)<<left<<value.first<<"="<<setw(10)<<right<<setfill(' ')<<value.second<<endl;
        }
        return sout;
    }
};

void solution(){
    music_player playlist;
    
    while(true){
        cout<<  "Choose any of the following options"
                "\nF -> Play first song"
                "\nN -> Play next song"
                "\nP -> Play previous song"
                "\nA -> Add new song"
                "\nL -> List the current playlist"
                "\nQ -> Exit"<<endl;
                
        string title,name;
        bool flag = false;
        string character;
        cin>>character;
        switch(character.at(0))
        {
            case 'F':
            case 'f':   playlist.first_song();break;
            case 'N':
            case 'n':   playlist.next_song();break;
            case 'P':
            case 'p':   playlist.previous_song();break;
            case 'A':
            case 'a':   cout<<"Enter title=";cin>>title;
                        cout<<"Enter name=";cin>>name;
                        playlist.add_song(title,name);
                        break;
            case 'l':
            case 'L':   cout<<playlist;break;
            case 'q':
            case 'Q':   flag = true;break;
            default :
                        cout<<"invalid character = "<<endl;break;
        }
        if(flag)break;
    }

    /*
        //Testing all funcitons
        list <pair<string,string>>song_list{
        pair<string,string>("title1","song1"),
        pair<string,string>("title2","song2"),
        pair<string,string>("title3","song3"),
        pair<string,string>("title4","song4")};
    
    music_player playlist(song_list);
    cout<<"playlist after adding all songs at once"<<endl;
    cout<<playlist;
    cout<<endl;

    playlist.add_song("title5","song5");
    cout<<"playlist after adding one song"<<endl;
    cout<<playlist;
    cout<<endl;

    playlist.next_song();
    playlist.next_song();
    playlist.next_song();
    playlist.next_song();
    playlist.next_song();
    playlist.next_song();
    playlist.next_song();

    cout<<endl<<"playing first song again"<<endl;
    playlist.first_song();
    cout<<endl;

    playlist.previous_song();
    playlist.previous_song();
    playlist.previous_song();
    playlist.previous_song();
    playlist.previous_song();
    playlist.previous_song();
    playlist.previous_song();*/
}

int main(){
    solution();
    return 0;
}