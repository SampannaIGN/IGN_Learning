/*

* responses.txt file has words every line and 
the first word tells us the correct answer and
remaining words will be name followed by student answer
* The tast is to calculate the scores of each student
with respect to the correct answer and display it.
* Finally print the average of score in proper format.

*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int get_score(string correct_response, string response){
    int score = 0;
    int length = response.length();
    for(int i = 0; i < length; i++){
        if(correct_response.at(i) == response.at(i))score++;
    }
    return score;
}

void solution(){
    ifstream input_file;
    input_file.open("Files//responses.txt");

    if(!input_file){
        cerr<<"Error opening the file"<<endl;
        return;
    }
    string correct_ans;
    input_file>>correct_ans;
    
    string name;
    string response;
    double avg = 0.0;
    int student_count = 0;

    cout<<setw(40)<<left<<"Student"<<setw(40)<<left<<"Score"<<endl;
    for(int i = 0; i < 80; i++)cout<<"-";cout<<endl;

    while(!input_file.eof()){
        input_file>>name;
        input_file>>response;
        int score = get_score(correct_ans,response);
        cout<<setw(40)<<left<<name<<setw(40)<<left<<score<<endl;
        avg += score;
        student_count++;
    }
    for(int i = 0; i < 80; i++)cout<<"-";cout<<endl;

    avg = avg/student_count;
    cout<<setw(40)<<left<<"Average Score"<<setw(40)<<left<<avg<<endl;
    input_file.close();
}

int main(){
    solution();
    return 0;
}