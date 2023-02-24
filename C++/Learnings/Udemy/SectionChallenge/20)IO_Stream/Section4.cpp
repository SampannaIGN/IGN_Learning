/*
* Read from romeoandjuliet.txt file
* Add line numbers to all the lines which have content int them.
*/

#include <iostream>
#include <fstream>

using namespace std;

void solution(){
    ofstream output_file;
    ifstream input_file;

    output_file.open("Files//output.txt");
    input_file.open("Files//romeoandjuliet.txt");

    if(!output_file){
        cerr<<"Error creating file output.txt"<<endl;
        return;
    }

    string line;
    int line_number = 0;
    while(getline(input_file,line)){
        if(line == "")continue;
        if(line.length() == 1 && line.at(0) == '\r'){output_file<<'\r';continue;}
        output_file<<++line_number<<")"<<line<<endl;
    }

    input_file.close();
    output_file.close();
}

int main(){
    solution();
    return 0;
}