/*
Part1 =>
Find all the words in a file and display count of those words

Part2 =>
Find all the words and display line numbers of all those words
*/
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <set>

using namespace std;

/*trims the string based on ,:.;*/
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

void update_map(map <string,set<int>>&my_map, string input, int line){
    istringstream new_stream(input);
    string str;
    while(new_stream>>str){
        string new_str = clean_string(str);
        int count = my_map.count(new_str);

        if(count == 0){
            set <int>my_set;
            my_set.insert(line);
            my_map[new_str] = my_set;
        }
        else{
            my_map[new_str].insert(line);
        }
    }
}

void solution_part1(){
    ifstream input_stream;
    map <string,int>my_map;

    input_stream.open("words.txt");
    
    if(!input_stream){
        cerr<<"Error opening file"<<endl;
        return;
    }

    while(!input_stream.eof()){
        string str;
        input_stream>>str;
        str = clean_string(str);
        
        int count = my_map.count(str);

        if(count == 0)my_map[str] = 1;
        else my_map[str]++;
        
    }
    
    for(pair <string,int>my_pair:my_map)
        cout<<my_pair.first<<" = "<<my_pair.second<<endl;

    input_stream.close();
}

void solution_part2(){
    ifstream input_stream;
    string input;
    map <string,set<int>>my_map;
    int line = 0;

    input_stream.open("words.txt");
    
    if(!input_stream){
        cerr<<"Error opening file"<<endl;
        return;
    }

    while(getline(input_stream,input)){
        line++;
        
        int count = my_map.count(input);
        update_map(my_map,input,line);
    }
    
    for(pair <string,set<int>>my_pair:my_map){
        cout<<my_pair.first<<" = ";
        cout<<"[";
        for(int value:my_pair.second)cout<<value<<" ";
        cout<<"]";
        cout<<endl;
    }

    input_stream.close();

}

int main(){
    //solution_part1();
    solution_part2();
    return 0;
}