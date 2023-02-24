#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;

/*iomanip i.e. formatting input values*/
void boolean_check(){
    cout<<(10==10)<<endl;
    cout.setf(ios::boolalpha);//or cout<<boolalpha;
    cout<<(10==10)<<endl;
    cout<<resetiosflags(ios::boolalpha);//or cout<<noboolalpha;
    cout<<(10==10)<<endl;
}

void int_check(){

    int x = 255;
    cout<<dec<<x<<endl;
    cout<<hex<<x<<endl;
    cout<<oct<<x<<endl;

    cout<<showbase<<uppercase;//shows base make it to upper case
    cout<<dec<<x<<endl;
    cout<<hex<<x<<endl;
    cout<<oct<<x<<endl;

    cout<<noshowbase<<nouppercase;//doesn't show base and make it to lower case
    //or cout<<resetiosflags(ios::uppercase)
    //   cout<<resetiosflags(ios::showbase)

    cout<<resetiosflags(ios::basefield);
    cout<<showpos;//shows +ve symbol if the number is positive
    //or cout<<resetiosflags(ios::showpos)
    cout<<x<<endl;
    cout<<noshowpos;
    //or cout<<resetiosflags(ios::noshowpos)
}

void float_check(){
    double x = 43333123432343.43444;
    
    cout<<x<<endl;//by default it will print 6 digits by rounding off
    cout<<setprecision(10)<<endl;//setting precision for overall digits
    cout<<x<<endl;
    
    cout<<fixed<<setprecision(9);//setting precision after decimal point
    cout<<x<<endl;
    cout<<resetiosflags(ios::floatfield);
    
    cout<<setprecision(4)<<scientific<<showpos;//setting precision & express scientfic notation
    cout<<x<<endl;
    cout<<resetiosflags(ios::floatfield|ios::showpos);//scientfic is also reset because
    //of floatfield os |ios::scientific would make no difference

    x = 34.34;
    cout<<setprecision(6)<<showpoint;//adds 0 at the end & makes overall precision 6
    cout<<x<<endl;
    cout<<resetiosflags(ios::floatfield|ios::showpoint);
}

void align_fill_check(){ 
    cout<<setw(10)<<right<<"abcd"<<setw(10)<<right<<"abcd"<<endl;//abcd will be right justified within a width of 10 twice
    cout<<setw(10)<<left<<"abcd"<<setw(10)<<left<<"abcd"<<endl;//abcd will be left justified within a width of 10 twice
    cout<<setw(10)<<left<<setfill('*')<<"abcd";//abcd will be left justified with * filled
    cout<<setw(10)<<right<<setfill('-')<<"abcd"<<endl;//abcd will be right justified with - filled
}

/*Reading from text file*/
void file_reading_pgm1(){
    ifstream input_file;
    input_file.open("Files/file1.txt");
    if(!input_file){
        cerr<<"Error opening file"<<endl;
        return;
    }
    string content;
    input_file>>content;//reads until the first space
    cout<<content<<endl;

    //while(!input_file.eof()){input_file>>content;cout<<content<<endl;}//reads until the end
    //of the file

    /*
    Reads line by line in the file
    while(getline(input_file,content)){
        cout<<content<<endl;
    }*/
    
    /*char current_char;
    while(input_file.get(current_char)){
        cout<<current_char;
    }*/

    input_file.close();
 }

/*Writing to text file*/
void file_writing_pgm1(){
    ofstream output_file;
    output_file.open("Files//file2.txt");//over writes
    //output_file.open("Files//file2.txt",ios::app);//appends to the text file
    if(!output_file){
        cerr<<"Error opening the file2.txt"<<endl;
        return;
    }
    string data;
    cout<<"Enter the data that you are going to enter into the file"<<endl;
    getline(cin,data);
    output_file<<data<<endl;

    output_file.close();
}

void copy_file(){
    ofstream output_file;
    ifstream input_file;
    
    input_file.open("Files//file1.txt");
    output_file.open("Files//file1Copy.txt");

    if(!output_file){
        cerr<<"Error opening the file1Copy.txt"<<endl;
        return;
    }
    
    char current_char;
    while(input_file.get(current_char)){
        output_file.put(current_char);
    }

    input_file.close();
    output_file.close();
  
}

void sstream_fun(){
    int int_value;
    string str_value;
    double double_value;

    string str = "10 abcdefg 10.2";

    istringstream input_stream{str};
    input_stream>>int_value>>str_value>>double_value;
    
    cout<<int_value<<" "<<str_value<<" "<<double_value<<endl;

    ostringstream output_stream;
    output_stream<<int_value<<" something "<<setw(10)<<right<<setfill('*')<<10;
    cout<<output_stream.str()<<endl;
}

void str_to_double(){
    string str = "12.3434";
    istringstream input_stream{str};
    double double_value;
    input_stream>>double_value;
    cout<<double_value<<endl;
}

int main(){
    // boolean_check();
    // int_check();
    // float_check();
    // align_fill_check();
    // file_reading_pgm1();
    // file_writing_pgm1();
    // copy_file();
    // sstream_fun();
    // str_to_double();
    return 0;
}